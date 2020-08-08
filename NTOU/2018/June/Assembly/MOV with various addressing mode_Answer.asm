; Title: MOV with various addressing mode
; Note: 

start:
	MOV A,#7BH
	MOV B,#0E5H
	MOV R0,#32
	MOV	R4,#89H
	MOV R7,#0C3H
; Addressing mode of the above = Immediate Addressing 
; The location of the data =  Code Memory 
; The content of Register R4 =  89H 
	MOV	A,R0
	MOV	R1,A
; Turn on switches 0, 1, 3, 4, and 6 for next instruction
	MOV	A,P2
	MOV	P1,A
; Addressing mode of the above = Register Addressing 
; The location of the data = Register 
; The number displayed in the left most 7-segment = 2 
	MOV	A,7H
	MOV	67H,A
	MOV	06H,A
; Addressing mode of the above = Direct Addressing 
; The location of the data = Data Memory 
; Switch from "Code Memory" to "Data Memory", the content of data 06H = c3 
	MOV	R0,#04H
	MOV	R1,#40H	
	MOV	A,@R0
	MOV	@R1,A
; Addressing mode of the above with @R0= Indirect Addressing 
; The content of data 40H = 89H 
	MOV DPH,#HIGH(table_of_LED_pattern)
	MOV DPL,#LOW(table_of_LED_pattern)
	MOV	A,#0
	MOVC	A,@A+DPTR
	MOV	P1,A
	MOV	A,#1
	MOVC	A,@A+DPTR
	MOV	P1,A
; Addressing mode of the above with @A+DPTR = Index Addressing 
; The location of the data = table pointed by DPTR, indexed by register A 
; Switch from "Data Memory" to "Code Memory", the address of label table_of_LED_pattern = 2FH 
; The conent of DP = 2FH 
	JMP	start

table_of_LED_pattern:
	db	0AAH 
	db	0FH