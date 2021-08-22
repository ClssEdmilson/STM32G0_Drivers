/*
 * STM32G071xx_GPIO.h
 *
 *  Created on: 21 de ago de 2021
 *      Author: edmil
 */

#ifndef INC_STM32G071XX_GPIO_H_
#define INC_STM32G071XX_GPIO_H_

#include "STM32G071xx.h"

/*
 * Struct para guardar os valores a serem configuradpr para o pino
 */

typedef struct {

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMOde;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPd;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunct;

}GPIO_PinConfig_t;


/*
 * Struct para configurar os registros das portas
 */

typedef struct {

	GPIO_RegDef_t *pGPIOx; 				// Definição da variavel tipo ponteiro que aponta para os endereços das portas
	GPIO_PinConfig_t GPIOPinConfig;		// Definição dos valores a serem atribuidos ao pino

}GPIO_Handle_t;


/*
 * Protótipos
 */

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle_t);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
void GPIO_PCLKControl(GPIO_RegDef_t *pGPIOx, uint8_t value);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
uint16_t GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_TglPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI );
void GPIO_IRQandle(uint8_t PinNumber);

#endif /* INC_STM32G071XX_GPIO_H_ */
