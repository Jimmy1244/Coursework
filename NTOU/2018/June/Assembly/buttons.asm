; This program scans the keypad.

; While no key is pressed the program
; scans row0, row1, row2, row3 and back to
; row0, continuously.

; When a key is pressed the key number
; is placed in R0.

; For this program, the keys are numbered
; as:

;	+----+----+----+
;	| 11 | 10 |  9 |	row3
;	+----+----+----+
;	|  8 |  7 |  6 |	row2
;	+----+----|----+
;	|  5 |  4 |  3 |	row1
;	+----+----+----+
;	|  2 |  1 |  0 |	row0
;	+----+----+----+
;	 col2 col1 col0

;	+---------+----------+---------+
;	| 0X06 | 0X5B |  0X4F |	row3
;	+---------+----------+---------+
;	|  0X4F |  0X66 |  0X6D |	row2
;	+---------+----------|----------+
;	|  0X7D |  0X07 |  0X7F |	row1
;	+---------+----------+---------+
;	|  0X77 |  0x3F |  0X7C |	row0
;	+---------+---------+----------+
;	 col2 col1 col0

; The pressed key number will be stored in
; R0. Therefore, R0 is initially cleared.
; Each key is scanned, and if it is not
; pressed R0 is incremented. In that way,
; when the pressed key is found, R0 will
; contain the key's number.

; The general purpose flag, F0, is used
; by the column-scan subroutine to indicate
; whether or not a pressed key was found
; in that column.
; If, after returning from colScan, F0 is
; set, this means the key was found.

start:
	MOV R0, #0			; clear R0 - the first key is key0
	MOV A,#10
	MOV DPTR,#TABLE
	; scan row0
	SETB P0.3			; set row3
	CLR P0.0			; clear row0
	CALL colScan		; call column-scan subroutine
	JB F0, finish		; | if F0 is set, jump to end of program 
						; | (because the pressed key was found and its number is in  R0)

	; scan row1
	SETB P0.0			; set row0
	CLR P0.1			; clear row1
	CALL colScan		; call column-scan subroutine
	JB F0, finish		; | if F0 is set, jump to end of program 
						; | (because the pressed key was found and its number is in  R0)

	; scan row2
	SETB P0.1			; set row1
	CLR P0.2			; clear row2
	CALL colScan		; call column-scan subroutine
	JB F0, finish		; | if F0 is set, jump to end of program 
						; | (because the pressed key was found and its number is in  R0)

	; scan row3
	SETB P0.2			; set row2
	CLR P0.3			; clear row3
	CALL colScan		; call column-scan subroutine
	JB F0, finish		; | if F0 is set, jump to end of program 
			
			; | (because the pressed key was found and its number is in  R0)


	JMP start			; | go back to scan row 0
						; | (this is why row3 is set at the start of the program
						; | - when the program jumps back to start, row3 has just been scanned)

finish:
	MOV A,R0
	MOVC A,@A+DPTR
	MOV P1,A
	CLR F0
	MOV P0, #0FFH
	JMP start	; program execution arrives here when key is found - do nothing


; column-scan subroutine
colScan:
	JNB P0.4, gotKey	; if col0 is cleared - key found
	INC R0				; otherwise move to next key
	JNB P0.5, gotKey	; if col1 is cleared - key found
	INC R0				; otherwise move to next key
	JNB P0.6, gotKey	; if col2 is cleared - key found
	INC R0				; otherwise move to next key
	RET					; return from subroutine - key not found
gotKey:
	SETB F0				; key found - set F0
	RET					; and return from subroutine	

DELAY: MOV R2, #300

TABLE:	DB	10000011B, 11000000B, 10001000B,10010000B
		DB	10000000B, 11111000B, 10000010B, 10010010B
		DB	10011001B, 10110000B, 10100100B, 11111001B
END