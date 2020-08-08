        ;PULSE副程式原來會呼叫DELAY
		;timer 0工作不變
		;設定timer 1, 每20us產生一次中斷，mode = 0, 1, or 2?
		;別忘了啟動timer 1以及timer 1的中斷
    	ORG     00H
	SJMP	START
	ORG		0BH
	SJMP	TIMER0
	ORG		01BH	
	DEC A	
	RETI
START:  
	MOV		SP,#60H
	MOV		TMOD,#022H
	SETB	EA
	SETB	ET0
	SETB	ET1
	MOV		TH0,#6
	MOV		TL0,#6
	MOV 	TH1,#-20
	MOV 	TL1,#-20
	MOV     DPTR,#TONE
	MOV		R0,#0
	MOV		R1,#20
	MOV		R2,#100
	;SETB PT1
	;CLR PT0
	SETB	TR0
	SETB	TR1
CheckTable:	
	MOV		A,R0
    MOVC    A,@A+DPTR
	MOV		R3,A
	ACALL	PLUSE1	
	SJMP	CheckTable
PLUSE1:  
	CJNE A,#0,PLUSE1
	CPL P1.0
	MOV A,R3
	CALL PLUSE2
	RET
PLUSE2:
	CJNE A,#0,PLUSE2
	CPL P1.0
	RET
TIMER0:			;一個音 兩ms * 250(time interrupt)
	DJNZ	R1,EXIT
	MOV		R1,#20
	DJNZ	R2,EXIT
	MOV		R2,#100
	INC		R0
	CJNE	R0,#8,EXIT
	MOV		R0,#0
	RETI	
EXIT:	
	RETI
TONE:
	DB      48      ;Do
	DB      43      ;Re
	DB      38      ;Mi
	DB      36      ;Fa
	DB      32      ;So
	DB      28      ;La
	DB      25      ;Si
	DB      24      ;H-Do
	END
