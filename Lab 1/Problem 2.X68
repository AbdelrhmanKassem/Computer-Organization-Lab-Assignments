*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
        LEA     MESSAGE,A1  load A1 with mem location assinged to MESSAGE
        MOVE.B  #14,D0      puts 14 into D0 to call task 14 in TRAP #15
        TRAP    #15         Displays MESSAGE
        MOVE.B  #2,D0       puts 2 into D0 to call task 2 in TRAP #15
        TRAP    #15         Takes user input and stores it in a memory location
                        ;and stores that location in A1
	    MOVEA.L	#RESULT,A2     move the address of the assigned storage to A2
NEXT
        MOVE.B  (A1)+,D0    move the first bit in the string to D0 and move to the next bit
        MOVE.B  (A1),D1     moves the second bit in the string to D1
        CMP.B   #$20,D0     checks if the bit is a space
        BEQ     SPACE       branch to SPACE
        CMP.B   #$00,D0     checks if the bit is the end charachter
        BEQ     DONE        brach to DONE
        MOVE.B  D0,(A2)+    if the bit is not a space and not the end character moves it to the new string
    	BRA	NEXT            moves to the next characters
    	
SPACE
        CMP.B   #$20,D1     checks if the next bit is also a space (I.E. two consicutive spaces)
        BEQ     NEXT        moves to the next bit
        CMP.B   #$00,D1     checks if the end character is after a space
        BEQ     ENDSPACE    brach to ENDSPACE
        MOVE.B  D0,(A2)+    move the space character to the new string
    	BRA	    NEXT        moves on to the next character

ENDSPACE   
        MOVE    D1,(A2)     moves the end character to the new string
        BRA     DONE        brach to DONE


DONE
        MOVE.B  #$00,(A2)   moves an end character to the new string
	    MOVEA.L	#RESULT,A1     moves the mem address to A1 to be printed out
        MOVE.B  #14,D0      puts 14 into D0 to call task 2 in TRAP #15
        TRAP    #15         displays the new string
    SIMHALT             ; halt simulator

* Put variables and constants here
CR      EQU     $0D      ASCII code for Carriage Return
LF      EQU     $0A      ASCII code for Line Feed
MESSAGE DC.B    'Enter the string with excess spaces below' , CR,LF,0 
RESULT	DS.B    1024     Defines 1024 of mem storage to store the new string
        END     START        ; last line of source



*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
