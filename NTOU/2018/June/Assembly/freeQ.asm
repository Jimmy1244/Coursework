MOV P1, #000H
MOV A, #080H
MOV 00h, #001H
MOV 01h, #080H

start:
	RR A
	MOV P1, A
	CJNE A ,00h, start;can not be A,Rn
	MOV R0, A;R0 = temp
	RL A
	ORL A, 1B
	MOV 00h, A
	MOV A, R0
	JMP start1
start1:
	RL A
	MOV P1, A
	CJNE A,01h, start1
	MOV R0, A;R0 = temp
	RR A
	ORL A, 080H
	MOV 01h, A
	MOV A, R0
	JMP start
	
	