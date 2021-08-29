/*
 * STM32G071xx_GPIO.c
 *
 *  Created on: 21 de ago de 2021
 *      Author: edmil
 */

#include "STM32G071xx_GPIO.h"

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	/*

	uint32_t temp = 0;




		temp = (pGPIOHandle->GPIOPinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIOPinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
		temp = 0;


	*/




	/*
	temp = (pGPIOHandle->GPIOPinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIOPinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;

	temp = (pGPIOHandle->GPIOPinConfig.GPIO_PinPuPd << (2 * pGPIOHandle->GPIOPinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;

	temp = (pGPIOHandle->GPIOPinConfig.GPIO_PinOPType << (1 * pGPIOHandle->GPIOPinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;
	*/




	Bit2Write(pGPIOHandle->pGPIOx->OSPEEDR, pGPIOHandle->GPIOPinConfig.GPIO_PinSpeed, pGPIOHandle->GPIOPinConfig.GPIO_PinNumber);
	Bit2Clr(pGPIOHandle->pGPIOx->MODER, pGPIOHandle->GPIOPinConfig.GPIO_PinNumber);
	Bit2Write(pGPIOHandle->pGPIOx->MODER, pGPIOHandle->GPIOPinConfig.GPIO_PinMode, pGPIOHandle->GPIOPinConfig.GPIO_PinNumber);
	Bit2Write(pGPIOHandle->pGPIOx->PUPDR, pGPIOHandle->GPIOPinConfig.GPIO_PinPuPd, pGPIOHandle->GPIOPinConfig.GPIO_PinNumber);

	BitWrite(pGPIOHandle->pGPIOx->OTYPER, pGPIOHandle->GPIOPinConfig.GPIO_PinOPType, pGPIOHandle->GPIOPinConfig.GPIO_PinNumber);

	if(pGPIOHandle->GPIOPinConfig.GPIO_PinMode == GPIO_MODE_ALT){
		if(pGPIOHandle->GPIOPinConfig.GPIO_PinNumber <= GPIO_PIN_8){
			BiteWrite(pGPIOHandle->pGPIOx->AFL[0], pGPIOHandle->GPIOPinConfig.GPIO_PinAltFunct, pGPIOHandle->GPIOPinConfig.GPIO_PinNumber);
		}else{
			BiteWrite(pGPIOHandle->pGPIOx->AFL[1], pGPIOHandle->GPIOPinConfig.GPIO_PinAltFunct, (pGPIOHandle->GPIOPinConfig.GPIO_PinNumber - 8));
		}
	}

};

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA){
		GPIOA_RESET();
	}

	else if(pGPIOx == GPIOB){
		GPIOB_RESET();
	}

	else if(pGPIOx == GPIOC){
		GPIOC_RESET();
	}

	else if(pGPIOx == GPIOD){
		GPIOD_RESET();
	}

	else if(pGPIOx == GPIOE){
		GPIOE_RESET();
	}

	else if(pGPIOx == GPIOF){
		GPIOF_RESET();
	};
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
	return ((uint8_t)BitTst(pGPIOx->IDR, PinNumber));
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx){
	return ((uint16_t)pGPIOx->IDR);
}

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value){
	if(value == ENABLE){
		BitSet(pGPIOx->ODR, PinNumber);
	}else{
		BitClr(pGPIOx->ODR, PinNumber);
	}
}

void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t value){
	pGPIOx->ODR = value;
}

void GPIO_TglPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	BitFlp(pGPIOx->ODR, PinNumber);
}

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI );
void GPIO_IRQandle(uint8_t PinNumber);

