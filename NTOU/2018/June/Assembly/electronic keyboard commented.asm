        ;PULSE副程式原來會呼叫DELAY
		;timer 0工作不變
		;設定timer 1, 每20us產生一次中斷，mode = 0, 1, or 2?
		;別忘了啟動timer 1以及timer 1的中斷
    ORG     00H
	SJMP	START
	ORG		0BH
	SJMP	TIMER0
	ORG		01BH
	SJMP	TIMER1
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
	SETB P1.0
	SETB	TR0
	SETB	TR1
CheckTable:	
	MOV		A,R0
    MOVC    A,@A+DPTR
	MOV		R3,A
	ACALL	PLUSE
	SJMP	CheckTable
PLUSE:  
	CJNE A,#0,PLUSE
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
TIMER1:
	DJNZ ACC,EXIT
	CPL P1.0	
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
