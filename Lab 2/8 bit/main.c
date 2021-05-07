#include <stdio.h>
#include <stdlib.h>


#define LDA 0
#define ADD 1
#define STA 2
#define BRA 3
#define BEQ 4
#define STOP 7

int main (void){

    unsigned short int  PC = 0;     /*program counter*/
    unsigned short int  D0 = 0;     /*data register*/
    unsigned short int  MAR;        /*memory address register*/
    unsigned short int  MBR;        /*memory buffer register*/
    unsigned short int  IR;         /*instruction register*/
    unsigned short int  operand;    /*the 8-bit operand from the IR*/
    unsigned short int  source;     /*source operand*/
    unsigned short int  opcode;     /*the 3-bit op-code from theIR*/
    unsigned short int  amode;      /*the 1-bit addressing mode*/
    unsigned short int  memory[16]={0b00000101,0b00110010,0b00100110,0b01000111,0b11100000,0b00001111,0b00000011}; /*the memory*/
    unsigned short int  run = 1;    /*execute program while run is 1*/



/*  Instruction format :                    */
/*  7   6   5   4   3   2   1   0           */
/*  Bits 3 to 0 4-bit operand               */
/*  Bit  4      1-bit addressing mode       */
/*  Bits 7 to 5 3-bit instruction code      */
/* main loop*/
    while (run)
    {
        MAR = PC;                   /*PC to MAR */
        PC = PC + 1; /* increment PC */
        MBR = memory[MAR]; /* get next instruction */
        IR = MBR; /* copy MBR to IR */

        opcode = IR >> 5; /* get the op-code */
        amode = (IR & 0x10) >> 4; /* extract the address mode bit */
        operand = IR & 0x0F; /* extract the operand */
        if (amode == 0) source = memory[operand]; else source = operand;
        switch (opcode) /* now execute the instruction */
            {
                case LDA: { D0 = source; break; }
                case STA: { memory[operand] = D0; break; }
                case ADD: { D0 = D0 + source; break; }
                case BRA: { PC = operand; break; }
                case BEQ: { if (D0 == 0) PC = operand; break; }
                case STOP: { run = 0; break; }
            }
    }
    for(int i=0;i<16;i++){
        printf("%d\n",memory[i]);
    }
    printf("\n\nD0: %d",D0);
    return 0;
}
