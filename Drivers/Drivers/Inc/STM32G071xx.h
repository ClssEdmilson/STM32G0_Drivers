/*
 * STM32G071xx.h
 *
 *  Created on: Aug 10, 2021
 *      Author: Edmilson Carlos dos Santos
 */

#ifndef INC_STM32G071XX_H_
#define INC_STM32G071XX_H_

#include<stdint.h>

#define BitSet(arg, bit)	((arg) |=  (1 << bit))
#define BitClr(arg, bit)	((arg) &= ~(1 << bit))
#define BitFlp(arg, bit) 	((arg) ^=  (1 << bit))
#define BitTst(arg, bit) 	((arg) &   (1 << bit))

/*
 * Memory addresses
 */

#define FLASH_MEM_BASEADDR		0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define SRAM					SRAM1_BASEADDR
#define SRAM2_BASEADDR			0x20001C00U
#define ROM						0x1FFF0000U

/*
 * Bus addresses
 */

#define PERIPH_BASEADDR			0x40000000U
#define APBPERIPH_BASEADDR		PERIPH_BASEADDR
#define AHBPERIPH_BASEADDR		0x40020000U
#define IO_PORT_BASEADDR		AHBPERIPH_BASEADDR

/*
 * AHB addresses peripherals
 */

#define DMA1_BASEADDR			(AHBPERIPH_BASEADDR + 0x0000)
#define DMA2_BASEADDR			(AHBPERIPH_BASEADDR + 0x0400)
#define DMAMUX_BASEADDR			(AHBPERIPH_BASEADDR + 0x0800)
#define RCC_BASEADDR			(AHBPERIPH_BASEADDR + 0x1000)
#define EXTI_BASEADDR			(AHBPERIPH_BASEADDR + 0x1800)
#define FLASH_BASEADDR			(AHBPERIPH_BASEADDR + 0x2000)
#define CRC_BASEADDR			(AHBPERIPH_BASEADDR + 0x3000)
#define RNG_BASEADDR			(AHBPERIPH_BASEADDR + 0x5000)
#define AES_BASEADDR			(AHBPERIPH_BASEADDR + 0x6000)

/*
 * APB addresses peripherals
 */

#define TIM2_BASEADDR			(APBPERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR			(APBPERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR			(APBPERIPH_BASEADDR + 0x0800)
#define TIM6_BASEADDR			(APBPERIPH_BASEADDR + 0x1000)
#define TIM7_BASEADDR			(APBPERIPH_BASEADDR + 0x1400)
#define TIM14_BASEADDR			(APBPERIPH_BASEADDR + 0x2000)
#define RTC_BASEADDR			(APBPERIPH_BASEADDR + 0x2800)
#define WWDG_BASEADDR			(APBPERIPH_BASEADDR + 0x2C00)
#define IWDG_BASEADDR			(APBPERIPH_BASEADDR + 0x3000)
#define SPI2_I2C2_BASEADDR		(APBPERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR			(APBPERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR			(APBPERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APBPERIPH_BASEADDR + 0x4800)
#define USART5_BASEADDR			(APBPERIPH_BASEADDR + 0x4C00)
#define I2C1_BASEADDR			(APBPERIPH_BASEADDR + 0x5000)
#define I2C2_BASEADDR			(APBPERIPH_BASEADDR + 0x5800)
#define USB_BASEADDR			(APBPERIPH_BASEADDR + 0x5C00)
#define FDCAN1_BASEADDR			(APBPERIPH_BASEADDR + 0x6400)
#define FDCAN2_BASEADDR			(APBPERIPH_BASEADDR + 0x6800)
#define CRS_BASEADDR			(APBPERIPH_BASEADDR + 0x6C00)
#define PWR_BASEADDR			(APBPERIPH_BASEADDR + 0x7000)
#define DAC_BASEADDR			(APBPERIPH_BASEADDR + 0x7400)
#define CEC_BASEADDR			(APBPERIPH_BASEADDR + 0x7800)
#define LPTIM1_BASEADDR			(APBPERIPH_BASEADDR + 0x7C00)
#define LPUART1_BASEADDR		(APBPERIPH_BASEADDR + 0x8000)
#define LPUART2_BASEADDR		(APBPERIPH_BASEADDR + 0x8400)
#define I2C3_BASEADDR			(APBPERIPH_BASEADDR + 0x8800)
#define LPTIM2_BASEADDR			(APBPERIPH_BASEADDR + 0x9400)
#define USB_RAM1_BASEADDR		(APBPERIPH_BASEADDR + 0x9800)
#define USB_RAM2_BASEADDR		(APBPERIPH_BASEADDR + 0x9C00)
#define UCPD1_BASEADDR			(APBPERIPH_BASEADDR + 0xA000)
#define UCPD2_BASEADDR			(APBPERIPH_BASEADDR + 0xA400)
#define SYSCFG_BASEADDR			(APBPERIPH_BASEADDR + 0x10000)
#define VREFBUF_BASEADDR		(APBPERIPH_BASEADDR + 0x10030)
#define SYSCFG_ITLINE_BASEADDR	(APBPERIPH_BASEADDR + 0x10080)
#define COMP_BASEADDR			(APBPERIPH_BASEADDR + 0x10200)
#define ADC_BASEADDR			(APBPERIPH_BASEADDR + 0x12400)
#define TIM1_BASEADDR			(APBPERIPH_BASEADDR + 0x12C00)
#define SPI1_I2S1_BASEADDR		(APBPERIPH_BASEADDR + 0x13000)
#define USART1_BASEADDR			(APBPERIPH_BASEADDR + 0x13800)
#define USART6_BASEADDR			(APBPERIPH_BASEADDR + 0x13C00)
#define TIM15_BASEADDR			(APBPERIPH_BASEADDR + 0x14000)
#define TIM16_BASEADDR			(APBPERIPH_BASEADDR + 0x14400)
#define TIM17_BASEADDR			(APBPERIPH_BASEADDR + 0x14800)
#define DBG_BASEADDR			(APBPERIPH_BASEADDR + 0x15800)

/*
 * IO PORT addresses peripherals
 */

#define GPIOA_BASEADDR			(IO_PORT_BASEADDR + 0x0000)
#define GPIOB_BASEADDR			(IO_PORT_BASEADDR + 0x0400)
#define GPIOC_BASEADDR			(IO_PORT_BASEADDR + 0x0800)
#define GPIOD_BASEADDR			(IO_PORT_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR			(IO_PORT_BASEADDR + 0x1000)
#define GPIOF_BASEADDR			(IO_PORT_BASEADDR + 0x1400)


/*
 * Struct for GPIO registers
 */

typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFL[2];
}GPIO_RegDef_t;


/*
 * Struct for GPIO registers
 */

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t ICSCR;
	volatile uint32_t CFGR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t RESERVED;
	volatile uint32_t CRRCR;
	volatile uint32_t CIER;
	volatile uint32_t CIFR;
	volatile uint32_t CICR;
	volatile uint32_t IOPRSTR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t APBRSTR1;
	volatile uint32_t APBRSTR2;
	volatile uint32_t IOPENR;
	volatile uint32_t AHBENR;
	volatile uint32_t APBENR1;
	volatile uint32_t APBENR2;
	volatile uint32_t IOPSMENR;
	volatile uint32_t AHBSMENR;
	volatile uint32_t APBSMENR1;
	volatile uint32_t APBSMENR2;
	volatile uint32_t CCIPR;
	volatile uint32_t CCIPR2;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_RegDef_t;

/*
 * Peripheral definition
 */

#define GPIOA	((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB	((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC	((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD	((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE	((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF	((GPIO_RegDef_t*)GPIOF_BASEADDR)

#define RCC	((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * GPIO Enable Clock
 */


#define GPIOA_CLK_EN()	(RCC->IOPENR |= (1 << 0))
#define GPIOB_CLK_EN()	(RCC->IOPENR |= (1 << 1))
#define GPIOC_CLK_EN()	(RCC->IOPENR |= (1 << 2))
#define GPIOD_CLK_EN()	(RCC->IOPENR |= (1 << 3))
#define GPIOE_CLK_EN()	(RCC->IOPENR |= (1 << 4))
#define GPIOF_CLK_EN()	(RCC->IOPENR |= (1 << 5))


/*
 * GPIO Disable Clock
 */

#define GPIOA_CLK_DIS()	(RCC->IOPENR &= ~(1 << 0))
#define GPIOB_CLK_DIS()	(RCC->IOPENR &= ~(1 << 1))
#define GPIOC_CLK_DIS()	(RCC->IOPENR &= ~(1 << 2))
#define GPIOD_CLK_DIS()	(RCC->IOPENR &= ~(1 << 3))
#define GPIOE_CLK_DIS()	(RCC->IOPENR &= ~(1 << 4))
#define GPIOF_CLK_DIS()	(RCC->IOPENR &= ~(1 << 5))


/*
 * Generic defines
 */

#define ENABLE  1
#define DISABLE 0
#define SET		ENABLE
#define RESET	DISABLE


#endif /* INC_STM32G071XX_H_ */
