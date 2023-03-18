/*
 * serialFromPC.h
 *
 *  Created on: Mar 18, 2023
 *      Author: Kyle
 */
 
#ifndef INC_SERIALFROMPC_H
#define INC_SERIALFROMPC_H
 
#define INSTR_BUFFER_SIZE 32

//type definitions 
typedef struct Instruction{
	int z; //z coordinate
	int th; //theta coordinate
	int r; //r coordinate
} Instruction;

//variable definitions
char instrBufferElements;
Instruction instrBuffer[INSTR_BUFFER_SIZE];
*Instruction instrStart,instrEnd,instrBufferLastIndex;


//function prototypes
void InitInstructionBuffer();
*Instruction ReadInstructionBuffer();
void WriteinstructionBuffer(Instruction i);
void InitSerialFromPC();

#endif
 
