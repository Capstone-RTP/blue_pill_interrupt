#include "stepperControl.h"

void initStepper(stepper * stepper, TIM_HandleTypeDef * tim, uint32_t  channel, GPIO_TypeDef * dirPort, uint16_t dirPin, uint32_t speed){

	//Initialize values
	stepper->Timer = tim;
	stepper->Channel = channel;
	stepper->DIRPort =dirPort;
	stepper->DIRPin = dirPin;
	stepper->PPS = speed;
	//update timer to align with speed
	setSpeed(stepper, stepper->PPS);
	//return stepper structure pointer
}


void setTarget (stepper * stepper, int increment){
	//if positive move forward and add to current position
	if( increment >= 0){
		stepper->TargetPosition+= increment;
	}
	//if negative move backward and take away from current position
	else{
		stepper->TargetPosition+= increment;
	}
	//if stepper isn't running, run and set direction
	if (stepper->Status == Stopped && stepper->CurrentPosition != stepper->TargetPosition){
		//find direction
		if(stepper->CurrentPosition > stepper->TargetPosition){
			HAL_GPIO_WritePin(stepper->DIRPort, stepper->DIRPin, SET);
			stepper->Status = RunningBackward;
		}
		else{
			HAL_GPIO_WritePin(stepper->DIRPort, stepper->DIRPin, RESET);
			stepper->Status = RunningForward;
		}
		//start pulses on timer
		HAL_TIM_PWM_Start(stepper->Timer, stepper->Channel);
	}
}

void setSpeed (stepper * stepper, uint32_t speed){
	//update pulse rate of stepper
	stepper->PPS = speed;
	//set duty cycle
	stepper->Timer->Instance->CCR1=1/(2*speed);
	//set timer period
	stepper->Timer->Instance->ARR=(1/speed)-1;
}
