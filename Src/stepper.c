#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "main.h"
#include "stepper.h"



#define horizontalStepPin GPIO_PIN_2
#define horizontalDirectionPin GPIO_PIN_3
#define horizontalPort GPIOG

#define vetricalStepPin GPIO_PIN_4
#define vetricalDirectionPin GPIO_PIN_5
#define verticalPort GPIOG

void SetDirection(GPIO_TypeDef * GPIOx,uint16_t pin,uint8_t direction);
void MakeStepInternal(GPIO_TypeDef * GPIOx,uint16_t pin);

void MakeStep(Steppers stepper, uint8_t direction)
{
	if(stepper==horizontal)
	{
      	SetDirection(horizontalPort,horizontalDirectionPin,direction);
		MakeStepInternal(horizontalPort,horizontalStepPin);
    }
	else 
	{
		SetDirection(verticalPort,vetricalDirectionPin,direction);
		MakeStepInternal(verticalPort,vetricalStepPin);
	}
	//SetDirection(GPIOB,GPIO_PIN_8,direction);
	//MakeStepInternal(GPIOB,GPIO_PIN_6);
}

void MakeStepInternal(GPIO_TypeDef * GPIOx,uint16_t pin)
{
		HAL_GPIO_TogglePin(GPIOx,pin);
	//HAL_Delay(50);
	osDelay(50);
	HAL_GPIO_TogglePin(GPIOx,pin);
	osDelay(50);
	//HAL_Delay(50);
}

void SetDirection(GPIO_TypeDef * GPIOx,uint16_t pin,uint8_t direction)
{
    
	if(direction==0)HAL_GPIO_WritePin(GPIOx,pin,0);
	else HAL_GPIO_WritePin(GPIOx,pin,1);
}