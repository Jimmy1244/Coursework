MOV R6,#0;R5 shiftATimes   R6 inputIndex   R7 length of MorseChar   R0 pos of MorseChar
Start:
;read InputTable
;for each character, call MorseChar
	;input: a character (either register or stack)
	MOV DPTR,#InputTable
	MOV A,R6			;INPUT INDEX
	INC R6			
	MOVC A,@A+DPTR	;lookup MorseTable
	CJNE A,#0,CountInput
	CALL Flash
	MOV R6,#0	
	JMP Start

MorseChar			:;input: a character (either register or stack)
	MOV DPTR,#InputTable
	MOV A,R6			;INPUT INDEX
	INC R6			
	MOVC A,@A+DPTR	;lookup MorseTable
	CJNE A,#0,CountInput
	CALL Flash
	MOV R6,#0	
	JMP Start
CountInput:
	SUBB A,#41H
	MOV B,#2
	MUL AB
	MOV R0,A
	MOV DPTR,#MorseTable
	MOVC A,@A+DPTR
	MOV R7,A
	MOV A,#8
	SUBB A,R7
	MOV R5,A
	MOV A,R0
	INC A
	MOVC A,@A+DPTR
	JMP ShiftA
ShiftA:
RL A
DJNZ R5,ShiftA
MOV P0,A
CALL CheckMorseTable

CheckMorseTable:
JB P0.7,OutDash
JNB P0.7,OutDot
RET

OutDot:
CALL DOT
MOV A,P0
RL A
MOV P0,A
DJNZ R7,CheckMorseTable
JMP MorseChar

OutDash:
CALL DASH
MOV A,P0
RL A
MOV P0,A
DJNZ R7,CheckMorseTable
JMP MorseChar

;output: Morse Code for input character

	RET

Dot:
	MOV	A, #0
	MOV	P1, A
	CALL Delay
	MOV	A, #0FFH
	MOV	P1, A
	CALL Delay
	RET
Dash:
	MOV	A, #0
	MOV	P1, A
	CALL Delay
	CALL Delay
	CALL Delay
	MOV	A, #0FFH
	MOV	P1, A
	CALL Delay
	RET
CharGap:
	CALL Delay
	CALL Delay
	CALL Delay
	CALL Delay
	CALL Delay
	RET
Flash:
	MOV	A, #55H
	MOV	P1, A
	CALL Delay
	MOV	A, #0AAH
	MOV	P1, A
	CALL Delay
	MOV	A, #055H
	MOV	P1, A
	CALL Delay
	MOV	A, #0AAH
	MOV	P1, A
	CALL Delay
	RET
Delay:
	RET
InputTable:
	DB	"HELLO"
	DB	0	;indication of the end
MorseTable:
	DB	2	;'A'
	DB	01B
	DB	4	;'B'
	DB	1000B
	DB	4	;'C'
	DB	1010B
	DB	3	;'D'
	DB	100B
	DB	1	;'E'
	DB	0B
	DB	4	;'F'
	DB	0010B
	DB	3	;'G'
	DB	110B
	DB	4	;'H'
	DB	0000B
	DB	2	;'I'
	DB	00B
	DB	4	;'J'
	DB	0111B
	DB	3	;'K'
	DB	101B
	DB	4	;'L'
	DB	0100B
	DB	2	;'M'
	DB	11B
	DB	2	;'N'
	DB	10B
	DB	3	;'O'
	DB	111B




