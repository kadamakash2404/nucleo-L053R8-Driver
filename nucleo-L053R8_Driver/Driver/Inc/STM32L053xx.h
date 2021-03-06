/*
 * STM32L053xx.h
 *
 *  Created on: Feb 21, 2022
 *      Author: kadam
 */

#ifndef INC_STM32L053XX_H_
#define INC_STM32L053XX_H_
#include <stdint.h>


#define __vo volatile


#define FLASH_PROGRAM_MEMORY_BASEADDR	0x08000000U		/* flash memory is up to 192 Kbyts*/
#define SRAM 							0X20002000U		/* STM32L0x3 devices feature up to 20 Kbytes of static SRAM.*/
#define ROM								0x1FF00000U		/* ROM is 8 Kbyts*/



#define PERIPH_BASE						0x40000000U
#define AHBPERIPH_BASE					0x40020000U
#define APB1PERIPH_BASE					0x40000000U
#define APB2PERIPH_BASE					0x40010000U
#define IOPORTPERIPH_BASE				0x50000000U


/*  Base address of peripherals which are hanging on AHB bus  */

#define DMA1_BASEADDR					(AHBPERIPH_BASE + 0x0000)
#define	RCC_BASEADDR					(AHBPERIPH_BASE + 0x1000)
#define FLASH_BASEADDR					(AHBPERIPH_BASE + 0x2000)
#define CRC_BASEADDR					(AHBPERIPH_BASE + 0x3000)
#define TSC_BASEADDR					(AHBPERIPH_BASE + 0x4000)
#define RNG_BASEADDR					(AHBPERIPH_BASE + 0x5000)
#define AES_BASEADDR					(AHBPERIPH_BASE + 0x6000)



/*  Base address of peripherals which are hanging on APB1 bus  */

#define TIMER2_BASEADDR					(APB1PERIPH_BASE + 0x0000)
#define TIMER3_BASEADDR					(APB1PERIPH_BASE + 0x0400)
#define TIMER6_BASEADDR					(APB1PERIPH_BASE + 0x1000)
#define TIMER7_BASEADDR					(APB1PERIPH_BASE + 0x1400)
#define LCD_BASEADDR					(APB1PERIPH_BASE + 0x2400)
#define RTC_BASEADDR					(APB1PERIPH_BASE + 0x2800)
#define WWDG_BASEADDR					(APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASEADDR					(APB1PERIPH_BASE + 0x3000)
#define SPI2_BASEADDR					(APB1PERIPH_BASE + 0x3800)
#define USART2_BASEADDR					(APB1PERIPH_BASE + 0x4400)
#define LPUART1_BASEADDR				(APB1PERIPH_BASE + 0x4800)
#define USART4_BASEADDR					(APB1PERIPH_BASE + 0x4C00)
#define USART5_BASEADDR					(APB1PERIPH_BASE + 0x5000)
#define I2C1_BASEADDR					(APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASE + 0x5800)
#define USB_FS_BASEADDR					(APB1PERIPH_BASE + 0x5C00)
#define USB_BASEADDR					(APB1PERIPH_BASE + 0x6000)
#define CRS_BASEADDR					(APB1PERIPH_BASE + 0x6C00)
#define PWR_BASEADDR					(APB1PERIPH_BASE + 0x7000)
#define DAC1_BASEADDR					(APB1PERIPH_BASE + 0x7400)
#define I2C3_BASEADDR					(APB1PERIPH_BASE + 0x7800)
#define LPTIM1_BASEADDR					(APB1PERIPH_BASE + 0x7C00)



/*  Base address of peripherals which are hanging on APB2 bus  */


#define SYSCFG_BASEADDR					(APB2PERIPH_BASE + 0x0000)
#define EXTI_BASEADDR					(APB2PERIPH_BASE + 0x0400)
#define TIM21_BASEADDR					(APB2PERIPH_BASE + 0x0800)
#define TIM22_BASEADDR					(APB2PERIPH_BASE + 0x1400)
#define Firewall_BASEADDR				(APB2PERIPH_BASE + 0x1C00)
#define ADC1_BASEADDR					(APB2PERIPH_BASE + 0x2400)
#define SPI1_BASEADDR					(APB2PERIPH_BASE + 0x3000)
#define USART1_BASEADDR					(APB2PERIPH_BASE + 0x3800)
#define DBG_BASEADDR					(APB2PERIPH_BASE + 0x5800)



/*  Base address of peripherals which are hanging on IOPORT bus  */


#define GPIOA_BASEADDR				(IOPORTPERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR				(IOPORTPERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR				(IOPORTPERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR				(IOPORTPERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR				(IOPORTPERIPH_BASE + 0x1000)
#define GPIOH_BASEADDR				(IOPORTPERIPH_BASE + 0x1C00)


/******************************** GPIO PERIPHERAL REGISTOR DEFINATION STRUCTURE **********************/

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFRL;
	__vo uint32_t AFRH;
	__vo uint32_t BRR;
}GPIO_RegDef_t;

/******************************** RCC PERIPHERAL REGISTOR DEFINATION STRUCTURE **********************/

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t ICSCR;
	__vo uint32_t CRRCR;
	__vo uint32_t CFGR;
	__vo uint32_t CIER;
	__vo uint32_t CIFR;
	__vo uint32_t CICR;
	__vo uint32_t IOPRSTR;
	__vo uint32_t AHBRSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t IOPENR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t IOPSMEN;
	__vo uint32_t AHBSMENR;
	__vo uint32_t APB2SMENR;
	__vo uint32_t APB1SMENR;
	__vo uint32_t CCIPR;
	__vo uint32_t CSR;

}RCC_RegDef_t;


/*
 * peripheral definition
 */

#define GPIOA 		((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB 		((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC 		((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD 		((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE 		((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOH 		((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define RCC			((RCC_RegDef_t*)  RCC_BASEADDR)




/*
 * Some Generic Macros
 */

#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET






/*
 * clock enable macro for GPIOx peripheral
 */

#define GPIOA_PCLK_EN()			(RCC -> IOPENR |= (1 << 0))
#define GPIOB_PCLK_EN()			(RCC -> IOPENR |= (1 << 1))
#define GPIOC_PCLK_EN()			(RCC -> IOPENR |= (1 << 2))
#define GPIOD_PCLK_EN()			(RCC -> IOPENR |= (1 << 3))
#define GPIOE_PCLK_EN()			(RCC -> IOPENR |= (1 << 4))
#define GPIOH_PCLK_EN()			(RCC -> IOPENR |= (1 << 7))



/*
 * clock enable macro for I2Cx peripheral
 */


#define I2C1_PCLK_EN() 			(RCC -> APB1ENR |= (1<< 21))
#define I2C2_PCLK_EN() 			(RCC -> APB1ENR |= (1<< 22))
#define I2C3_PCLK_EN() 			(RCC -> APB1ENR |= (1<< 30))



/*
 * clock enable macro for SPIx peripheral
 */

#define SPI1_PCLK_EN()			(RCC -> APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()			(RCC -> APB1ENR |= (1 << 14))


/*
 * clock enable macro for USARTx peripheral
 */

#define USART1_PCLK_EN()		(RCC -> APB2ENR |= (1 << 14))
#define USART2_PCLK_EN()		(RCC -> APB1ENR |= (1 << 17))
#define USART4_PCLK_EN()		(RCC -> APB1ENR |= (1 << 19))
#define USART5_PCLK_EN()		(RCC -> APB1ENR |= (1 << 20))
#define LPUART1_PCLK_EN()		(RCC -> APB1ENR |= (1 << 18))



/*
 * clock enable macro for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN()		(RCC -> APB2ENR |= (1 << 0))





/*
 * clock Disable macro for GPIOx peripheral
 */

#define GPIOA_PCLK_DI()			(RCC -> IOPENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()			(RCC -> IOPENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()			(RCC -> IOPENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()			(RCC -> IOPENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()			(RCC -> IOPENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()			(RCC -> IOPENR &= ~(1 << 7))



/*
 * clock Disable macro for I2Cx peripheral
 */


#define I2C1_PCLK_DI() 			(RCC -> APB1ENR &= ~ 1<< 21))
#define I2C2_PCLK_DI() 			(RCC -> APB1ENR &= ~(1<< 22))
#define I2C3_PCLK_DI() 			(RCC -> APB1ENR &= ~(1<< 30))



/*
 * clock Disable macro for SPIx peripheral
 */

#define SPI1_PCLK_DI()			(RCC -> APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()			(RCC -> APB1ENR &= ~(1 << 14))


/*
 * clock Disable macro for USARTx peripheral
 */

#define USART1_PCLK_DI()		(RCC -> APB2ENR &= ~(1 << 14))
#define USART2_PCLK_DI()		(RCC -> APB1ENR &= ~(1 << 17))
#define USART4_PCLK_DI()		(RCC -> APB1ENR &= ~(1 << 19))
#define USART5_PCLK_DI()		(RCC -> APB1ENR &= ~(1 << 20))
#define LPUART1_PCLK_DI()		(RCC -> APB1ENR &= ~(1 << 18))



/*
 * clock Disable macro for SYSCFG peripheral
 */

#define SYSCFG_PCLK_DI()		(RCC -> APB2ENR &= ~(1 << 0))








#endif /* INC_STM32L053XX_H_ */
