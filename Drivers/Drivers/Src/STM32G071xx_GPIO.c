/*
 * STM32G071xx_GPIO.c
 *
 *  Created on: 21 de ago de 2021
 *      Author: edmil
 */

#include "STM32G071xx_GPIO.h"

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle_t){

};

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

};

void GPIO_PCLKControl(GPIO_RegDef_t *pGPIOx, uint8_t value){

	if(value == ENABLE){

		if(pGPIOx == GPIOA){
			GPIOA_CLK_EN();
		}

		else if(pGPIOx == GPIOB){
			GPIOB_CLK_EN();
		}

		else if(pGPIOx == GPIOC){
			GPIOC_CLK_EN();
		}

		else if(pGPIOx == GPIOD){
			GPIOD_CLK_EN();
		}

		else if(pGPIOx == GPIOE){
			GPIOE_CLK_EN();
		}

		else if(pGPIOx == GPIOF){
			GPIOF_CLK_EN();
		};
	}else {
		if(pGPIOx == GPIOA){
			GPIOA_CLK_DIS();
		}

		else if(pGPIOx == GPIOB){
			GPIOB_CLK_DIS();
		}

		else if(pGPIOx == GPIOC){
			GPIOC_CLK_DIS();
		}

		else if(pGPIOx == GPIOD){
			GPIOD_CLK_DIS();
		}

		else if(pGPIOx == GPIOE){
			GPIOE_CLK_DIS();
		}

		else if(pGPIOx == GPIOF){
			GPIOF_CLK_DIS();
		};
	};
};

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

};

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx){

};

uint8_t GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value){

};

uint16_t GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t value){

};

void GPIO_TglPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

};

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI );
void GPIO_IRQandle(uint8_t PinNumber);

