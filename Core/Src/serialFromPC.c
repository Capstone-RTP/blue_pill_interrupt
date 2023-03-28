#include "serialFromPC.h"

char instrBufferElements;
uint8_t newLine = '\n';
uint8_t carriageReturn = '\r';
uint8_t usartOutputBuffer[OUTPUT_BUFFER_SIZE];

UART_HandleTypeDef* huart;

void InitSerialFromPC(UART_HandleTypeDef* huartHandler){
	huart = huartHandler;
	//allocate for buffer
	usartInputBuffer = (uint8_t*)calloc(INPUT_BUFFER_SIZE,sizeof(uint8_t));
}

void SendSerialNewLine(){
	HAL_UART_Transmit(huart,&newLine,1,10);
	HAL_UART_Transmit(huart,&carriageReturn,1,10);
}

void SendSerialInt(uint16_t message){
	//get number of characters for message
	uint16_t length = snprintf(NULL, 0, "%d", message);
	//copy string into buffer
	snprintf(usartOutputBuffer, length + 1, "%d", message);
	//print to usart
	HAL_UART_Transmit(huart,usartOutputBuffer,length,10);
	SendSerialNewLine();
}

uint8_t* GetInputBufferAddress(){
	return usartInputBuffer;
}

/*
void InitInstructionBuffer(){
	instrBufferElements = 0;
	instrBufferLastIndex = (*Instruction)(INSTR_BUFFER_SIZE);
	instrStart = instrBuffer;
	instrEnd = instrBuffer;
}
*/

/*
*Instruction ReadInstructionBuffer(){
	*Instruction i = start;
	instrStart++;
	if(instrStart > instrBuffer + (*Instruction)){
		instrStart = instrBuffer;
	}
	
	instrBufferElements--;
	return i;
}

void WriteInstructionBuffer(Instruction i){
	instrEnd++
	
}
*/
