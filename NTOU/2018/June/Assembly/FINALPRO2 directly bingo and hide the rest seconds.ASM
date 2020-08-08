;利用中断的99秒计时器 ，动态扫描两位数码管
;P0口接J3，数据端口
;P2.2接 J2 B端子，表示段码锁存
;P2.3接 J2 A端子，标志位码锁存

LATCH1 EQU P2.2
LATCH2 EQU P2.3

ORG 00H
JMP START
ORG 0BH
JMP TIM0
START:MOV R3,#00   ;中断循环次数
      MOV R4,#0    ;时间初值
      MOV R5,#1     ;分鐘數
      MOV P3, #0FFH
      ;MOV 20H,#0	  ;歸零個位
      ;MOV 21H,#0   ;歸零十位
      MOV DPTR,#TABLE
      MOV SP,#40H
      MOV TMOD,#01H  ;定时器工作方式 16 bits
      MOV TH0,#HIGH(-3800)
      MOV TL0,#LOW(-3800)  ;初值4MS
      SETB TR0     ;Timer 0開始
      MOV IE,#82H  ;开中断
TIM0:
     MOV TH0,#HIGH(-3800)
     MOV TL0,#LOW(-3800)    
     INC R3
     CJNE R3,#180,X1  ;1S
     MOV R3,#0

     MOV A,R4
     SUBB A,#1
     MOV R4,A
     MOV A,R4       ;十进制转换
     MOV B,#10
     DIV AB
     MOV 20H,B  ; 个位
     MOV 21H,A  ; 十位     
     CJNE R4,#-1,LEDSCAN  ;到0扣分鐘數
     MOV 20H,#9	  ;歸零個位
     MOV 21H,#5   ;歸零十位
     MOV R4,#59
     MOV A,R5
     SUBB A,#1
     MOV R5,A
     CJNE R5,#-1,LEDSCAN
     CLR TR0
     JMP EXPLOSION
LEDSCAN: CALL SCAN  ;调用数码管扫描
X1:   PUSH ACC
      PUSH PSW
      CALL SCAN
      POP PSW
      POP ACC
      RETI
KEY:
	 MOV R0, #0			; clear R0 - the first key is key0
	 MOV A,#10
		; scan row0
	 SETB P3.3			; set row3
	 CLR P3.0			; clear row0
	 CALL colScan		; call column-scan subroutine
	 JB F0, finish		; | if F0 is set, jump to end of program 
						; | (because the pressed key was found and its number is in  R0)

		; scan row1
	 SETB P3.0			; set row0
	 CLR P3.1			; clear row1
	 CALL colScan		; call column-scan subroutine
	 JB F0, finish		; | if F0 is set, jump to end of program 
						; | (because the pressed key was found and its number is in  R0)

		; scan row2
	 SETB P3.1			; set row1
	 CLR P3.2			; clear row2
	 CALL colScan		; call column-scan subroutine
	 JB F0, finish		; | if F0 is set, jump to end of program 
						; | (because the pressed key was found and its number is in  R0)

		; scan row3
	 SETB P3.2			; set row2
	 CLR P3.3			; clear row3
	 CALL colScan		; call column-scan subroutine
	 JB F0, finish		; | if F0 is set, jump to end of program 

	 RET	
SCAN:
     MOV A,21H
     MOVC A,@A+DPTR
     MOV P0,A
     SETB LATCH1
     CLR LATCH1
     MOV P0,#11111101B ;扫描子程序
     SETB LATCH2
     CLR LATCH2
     CALL DELAY1

     MOV A,20H
     MOVC A,@A+DPTR
     MOV P0,A
     SETB LATCH1
     CLR LATCH1
     MOV P0,#11111011B  ;0代表选通该位数码管
     SETB LATCH2
     CLR LATCH2
     CALL DELAY1

     MOV A,R5
     MOVC A,@A+DPTR
     MOV P0,A
     SETB LATCH1
     CLR LATCH1
     MOV P0,#11111110B  ;0代表选通该位数码管
     SETB LATCH2
     CLR LATCH2
     CALL DELAY1

     RET
finish:
    CJNE R0,#4,TIM0
	MOV P1,#0FFH
	MOV P1,#01010101B
	CLR TR0	
	CALL BINGO
colScan:
	JNB P3.4, gotKey	; if col0 is cleared - key found
	INC R0				; otherwise move to next key
	JNB P3.5, gotKey	; if col1 is cleared - key found
	INC R0				; otherwise move to next key
	JNB P3.6, gotKey	; if col2 is cleared - key found
	INC R0				; otherwise move to next key
	RET					; return from subroutine - key not found
gotKey:
	MOV P3, #0FFH
	JMP finish
	SETB F0				; key found - set F0
	RET					; and return from subroutine	
DELAY1:MOV R6,#4    ;扫描延时
D3:    MOV R7,#248
       DJNZ R7,$
       CALL KEY
       DJNZ R6,D3
       RET
BINGO:
	 MOV P0, #00H
	 SETB LATCH1
     CLR LATCH1
     MOV P0,#00H  ;0代表选通该位数码管
     SETB LATCH2
     CLR LATCH2
     CALL DELAY1
     JMP BINGO
EXPLOSION:
	MOV P1,#0FFH
	CALL D3
	MOV P1,#0H
	CALL D3
	JMP EXPLOSION
TABLE:DB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH    ;共阴字码表
END
