*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG    $1000
START:                  ; first instruction of program

* Put program code here
    MOVE    #8,D3       moves the number 8 to D3 to be used in the loop

OUTERLOOP
    LEA     LIST,A1     load the list location into address register 1 
    SUB.B   #1,D3       subtracts 1 from the loop counter
    BEQ     DONE        if loop is over go to done
    MOVE    #8,D4       moves 8 to D3 to be used as inner loop counter
INNERLOOP
    MOVE.B  (A1)+,D1    moves a list item to D1
    MOVE.B  (A1),D2     moves the next item to D2
    CMP.B   D1,D2       compare the 2 selected items
    BMI     NOSWAP      if D2>D1 the don't swap them
    MOVE.B  D1,(A1)     this line and the next line are used to
    MOVE.B  D2,-(A1)    swap the two selected items in the list
    ADDA.L  #2,A1       adds 2 to A1 to negate the subtraction in the last step
NOSWAP
    SUB.B   #1,D4       subtracts 1 from the inner loop counter
    BEQ     OUTERLOOP   if inner loop is done then restart the outer loop
    BRA     INNERLOOP   else re-enter the inner loop
  

DONE
    LEA     LIST,A1     load the list location back into address register 1
    

    SIMHALT             ; halt simulator

* Put variables and constants here
LIST DC.B   1,2,5,4,8,5,4,2     the list
    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
