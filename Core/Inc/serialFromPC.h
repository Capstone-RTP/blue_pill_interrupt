/*
 * serialFromPC.h
 *
 *  Created on: Mar 18, 2023
 *      Author: Kyle
 */
 
#ifndef INC_SERIALFROMPC_H
#define INC_SERIALFROMPC_H
 
#define INSTR_BUFFER_SIZE 32
#define OUTPUT_BUFFER_SIZE 64
#define INPUT_BUFFER_SIZE 64

#include <stdint.h>
#include <stdio.h>
#include "stm32f1xx.h"

static uint8_t *usartInputBuffer;

//type definitions 
typedef struct Instruction{
	int z; //z coordinate
	int th; //theta coordinate
	int r; //r coordinate
} Instruction;

//variable definitions

//Instruction instrBuffer[INSTR_BUFFER_SIZE];
//Instruction* instrStart,instrEnd,instrBufferLastIndex;

//function prototypes
/*
void InitInstructionBuffer();
Instruction* ReadInstructionBuffer();
void WriteinstructionBuffer(Instruction i);
*/
void InitSerialFromPC(UART_HandleTypeDef* huartHandler);
void SendSerialInt(uint16_t message);
void SendSerialNewLine();
uint8_t* GetInputBufferAddress();

#endif
 
