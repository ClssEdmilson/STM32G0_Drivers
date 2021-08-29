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
	uint8_t GPIO_PinMode;
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
 * Modes
 */

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALT		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RTFT	6

#define GPIO_OUT_PP		0
#define GPIO_OUT_OD		1

#define GPIO_SPEED_LOW	0
#define GPIO_SPEED_MID	1
#define GPIO_SPEED_FAST	2
#define GPIO_SPEED_HIGH 3

#define NO_PUPD		0
#define PULL_UP		1
#define PULL_DOWN	2

#define GPIO_PIN_0	0
#define GPIO_PIN_1	1
#define GPIO_PIN_2	2
#define GPIO_PIN_3	3
#define GPIO_PIN_4	4
#define GPIO_PIN_5	5
#define GPIO_PIN_6	6
#define GPIO_PIN_7	7
#define GPIO_PIN_8	8
#define GPIO_PIN_9	9
#define GPIO_PIN_10	10
#define GPIO_PIN_11	11
#define GPIO_PIN_12	12
#define GPIO_PIN_13	13
#define GPIO_PIN_14	14
#define GPIO_PIN_15	15




/*
 * Protótipos
 */

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle_t);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
void GPIO_PCLKControl(GPIO_RegDef_t *pGPIOx, uint8_t value);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_TglPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI );
void GPIO_IRQandle(uint8_t PinNumber);

#endif /* INC_STM32G071XX_GPIO_H_ */
