*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
    MOVE #0,D1		Clears D1 for addition
    MOVE.B P(PC),D0	Moves 6 to D0
    ADD.B D0,D1		Adds 6 to D1 
    MOVE.B Q(PC),D0	Moves 4 to D0
    ADD.B D0,D1		Adds 4 to D1
    MOVE.B R(PC),D0	Moves 12 to D0
    ADD.B D0,D1		Adds 12 to D1
    MOVE.B S(PC),D0	Moves 16 to D0
    ADD.B D0,D1		Adds 16 to D1
    MOVE.B T(PC),D0	Moves 17 to D0
    ADD.B D0,D1		Adds 17 to D1
    MOVE.B U(PC),D0	Moves 50 to D0
    ADD.B D0,D1		Adds 50 to D1
    MOVE.B D1,RESULT	Move the result to memory address RESULT (can't use relative addressing in distination)
    MOVE.B #3,D0	Moves 3 to D0 to use task no. 3 from TRAP#15
    TRAP #15		displays the number in D1.L
    SIMHALT             ; halt simulator

* Put variables and constants here
P   DC.B    6		Defines constant P and puts it as 6
Q   DC.B    4		Defines constant Q and puts it as 4
R   DC.B    12		Defines constant R and puts it as 12
S   DC.B    16		Defines constant S and puts it as 16
T   DC.B    17		Defines constant T and puts it as 17
U   DC.B    50		Defines constant U and puts it as 50
RESULT DS.B 1		Defines a byte storage to the result
    END    START        ; last line of source


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
