        ORG     	00H
	SJMP		START
	ORG		0BH
	SJMP		TIMER0
START:  
	MOV		SP,#60H
	MOV		TMOD,#2
	SETB		EA
	SETB		ET0
	MOV		TH0,#6
	MOV		TL0,#6
	MOV     	DPTR,#TONE
	MOV		R0,#0
	MOV		R1,#20
	MOV		R2,#100
	SETB		TR0
LOOP:	
	MOV		A,R0
        MOVC    	A,@A+DPTR
	MOV		R3,A
	ACALL	PLUSE
	SJMP		LOOP
PLUSE:  
	MOV     	A,R3
	SETB   	P1.0
	ACALL   	DELAY
	MOV     	A,R3
	CLR     	P1.0
	ACALL   	DELAY
	RET
TIMER0:	
	DJNZ		R1,EXIT
	MOV		R1,#20
	DJNZ		R2,EXIT
	MOV		R2,#100
	INC		R0
	CJNE		R0,#8,EXIT
	MOV		R0,#0
EXIT:	
	RETI
DELAY:  
	NOP
	MOV     	R4,#8
	DJNZ    	R4,$
	DJNZ    	ACC,DELAY
	RET
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
