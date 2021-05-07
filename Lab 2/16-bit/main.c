#include <stdio.h>
#include <stdlib.h>


#define MOVE 0
#define ADD 1
#define SUB 2
#define BRA 3
#define CMP 4
#define BEQ 5
#define BNE 6
#define EXG 7 /*EXG exchanges the contents of two registers */
#define AND 8
#define OR  9
#define XOR 10
#define STOP 15

void main (void)

{
    unsigned short int PC = 0; /* program counter */
    unsigned short int D0 = 0; /* data register */
    unsigned short int A0 = 0; /* address register */
    unsigned short int CCR = 0; /* condition code register */
    unsigned short int MAR; /* memory address register */
    unsigned short int MBR; /* memory buffer register */
    unsigned short int IR; /* instruction register */
    unsigned short int operand; /* the 8-bit operand from the IR */
    unsigned short int source; /* source operand */
    unsigned short int destination; /* the destination value */
    unsigned short int opcode; /* the 4-bit op-code from the IR */
    unsigned short int amode; /* the 2-bit addressing mode */
    unsigned short int direction; /* the 1-bit data direction flag */
    unsigned short int memory[256] = {0b00000100,0b00010100,0b10000100,0b00010101,0b00000000,0b00010110,0b00000100,0b00010100,0b10010100,0b00010101,0b00000000,0b00010111,0b00000100,0b00010100,0b10100100,0b00010101,0b00000000,0b00011000,0b11110000,0b00000000,0b10110111,0b11001011,0b10000011	,0b11111111,0b01111100}; /* the memory */
    unsigned short int run = 1; /* execute program while run is 1 */
    /* Instruction format: */
    /* 7    6   5   4   3   2   1   0 */
    /* Bit 1 and O 2-bit address mode */
    /* 00 address mode - absolute */
    /* 0l address mode = literal */
    /* 10 address mode = indexed */
    /* 11 address mode = relative */
    /* Bit 2 1-bit direction (source/operand) */
    /* Bit 3 not used */
    /* Bit 7 to 4 4-bit instruction code */
    /* main loop */
    while (run)
    {
        MAR = PC; /* PC to MAR */
        PC = PC + 1; /* increment PC */
        MBR = memory[MAR] ; /* get next instruction */
        IR = MBR; /* copy MBR to IR */
        opcode = IR; /* store the op-code bits */
        MAR = PC; /* PC to MAR */
        PC = PC + 1; /* increment PC */
        MBR = memory[MAR]; /* get the operand */
        IR = MBR; /* copy MBR t0 IR */
        operand = IR; /* store the operand bits */
        amode = opcode & 0x03; /* extract the address mode bits */
        direction = (opcode & 0x04) >> 2; /* get data direction 0 = register to memory
        1 = memory to register */
        opcode = opcode >> 4; /* get the 4-bit instruction code */
        /* use the address mode to get the source operand */
        switch (amode){
            case 0: {source = memory [operand]; break;} /* absolute */
            case 1: {source = operand; break;} /* literal */
            case 2: {source = memory[A0 + operand]; break;} /* indexed */
            case 3: {source = memory[PC + operand]; break;} /* PC relative */

        }

        /* now execute the instruction */
        switch (opcode){
            case MOVE: {
                if (direction == 0) destination = D0;else D0 = source;
                if (D0 == 0) CCR = 1; else CCR = 0; /* update CCR */
                break;
                }
            case ADD: {
                if (direction == 0){
                    destination = D0 + source;
                    if (destination == 0) CCR = 1; else CCR = 0;
                }
                else{
                    D0 = D0 + source;
                    if (D0 == 0 ) CCR = 1; else CCR = 0;
                }
                break;
                }
            case SUB: {
                if (direction == 0){
                        destination = D0 - source;
                        if (destination == 0) CCR = 1; else CCR = 0;
                }
                else{
                    D0 = D0 - source;
                    if (D0 == 0 ) CCR = 1; else CCR = 0;
                }
                break;
            }
            case BRA: {
                if (amode == 0) PC = operand;
                if (amode <= 1) PC = PC + operand; break;
            }
            case CMP: {
                MBR = D0 - source;
                if (MBR == 0) CCR = 1;
                else CCR = 0; break;
            }
            case BEQ: {
                if (CCR == 1){
                        if (amode == 0) PC = operand;
                        if (amode == 1) PC = PC + operand;
                }
                break;
            }
            case BNE: {
                if (CCR != 1){
                    if (amode == 0) PC = operand;
                    if (amode == 1) PC = PC + operand;
                    }
                break;
            }
            case EXG: {
                MBR = D0; D0 = A0; A0 = MBR;
                break;
            }
            case AND: {
                    if (direction == 0)
                    destination = D0 & source;
                else
                    D0 = D0 & source;
                break;
            }
            case OR: {
                    if (direction == 0)
                    destination = D0 | source;
                else
                    D0 = D0 | source;
                break;
            }
            case XOR: {
                    if (direction == 0)
                    destination = D0 ^ source;
                else
                    D0 = D0 ^ source;
                break;
            }
            case STOP: {
                run = 0;
                break;
            }
        }
/* save result in memory if register to memory */
        if (direction == 0)
        switch (amode){
            case 0: {
                memory[operand] = destination; break; /* absolute */
            }
            case 1: {
            break; /* literal */
            }
            case 2: {
                memory[A0 + operand] = destination; break; /* indexed */
            }
            case 3: {
                memory[PC + operand] = destination; break; /* PC relative */
            }
        }
    }
    for(int i=20;i<25;i++){
        printf("Memory Location %d : %d\n",i,memory[i]);
    }
}
