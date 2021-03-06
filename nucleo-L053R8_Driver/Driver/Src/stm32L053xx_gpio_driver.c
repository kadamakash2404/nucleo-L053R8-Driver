/*
 * stm32L053xx_gpio.c
 *
 *  Created on: 22-Feb-2022
 *      Author: kadam
 */


#include "stm32L053_gpio_driver.h"



/*****************************************
 * peripheral clock setup
 *****************************************/


 /* @fn				:	GPIO_PeriClkControl
 *
 * @brif			:	enable or disable clock to gpio peripheral
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:	ENABLE or DISABLE macro
 * @param[in]		:
 *
 * @return			:	none
 *
 * @note			:
 */
void GPIO_PeriClkControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}
}



/********************************
 * Init and DeInit
 ********************************/

/* @fn				:	GPIO_Init
 *
 * @brif			:	Initialize GPIO peripheral
 *
 * @param[in]		:	pointer to the handle structure
 * @param[in]		:
 * @param[in]		:
 *
 * @return			:	none
 *
 * @note			:
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		uint32_t temp = 0;
		//1. configure the mode of gpio pin
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
		temp = 0;

		//2. configure the speed
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OSPEEDR |= temp;
		temp = 0;


		//3. configure the pupd settings
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl <<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->PUPDR |= temp;
		temp = 0;


		//4. configure the output type
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OTYPER |= temp;
		temp = 0;
	}

	//5. confugure the alt functionality

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFUN)
	{

	}




}











/* @fn				:	GPIO_DeInit
 *
 * @brif			:	Disable GPIO peripheral
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:
 * @param[in]		:
 *
 * @return			:	none
 *
 * @note			:
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

}














/**********************************
 *  Data Read and Write
 **********************************/



/* @fn				:	GPIO_ReadFromInputPin
 *
 * @brif			:	read data at specific pin on GPIO port
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:	GPIO pin number
 * @param[in]		:
 *
 * @return			:	uint8_t data
 *
 * @note			:
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	return 0;
}







/* @fn				:	GPIO_ReadFromInputPort
 *
 * @brif			:	read data at GPIO port
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:
 * @param[in]		:
 *
 * @return			:	uint16_t data
 *
 * @note			:
 */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	return 0;
}








/* @fn				:	GPIO_WriteToOutputPin
 *
 * @brif			:	Write data at specific pin on GPIO port
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:	Pin number onGPIO port
 * @param[in]		:	value SET or RESET
 *
 * @return			:	none
 *
 * @note			:
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{

}







/* @fn				:	GPIO_WriteToOutputPort
 *
 * @brif			:	Write data at GPIO port
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:	value 16bit
 * @param[in]		:
 *
 * @return			:	none
 *
 * @note			:
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{

}







/* @fn				:	Gpio_ToggleOutputPin
 *
 * @brif			:	toggle specific pin on and off
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:	GPIO pin number
 * @param[in]		:
 *
 * @return			:	none
 *
 * @note			:
 */
void Gpio_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}










/******************************************
 * IRQ configuration and handling
 ******************************************/



/* @fn				:	GPIO_IRQConfig
 *
 * @brif			:	toggle specific pin on and off
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:	GPIO pin number
 * @param[in]		:
 *
 * @return			:	none
 *
 * @note			:
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}









/* @fn				:	GPIO_IRQHandling
 *
 * @brif			:	toggle specific pin on and off
 *
 * @param[in]		:	base address of GPIO port
 * @param[in]		:	GPIO pin number
 * @param[in]		:
 *
 * @return			:	none
 *
 * @note			:
 */
void GPIO_IRQHandling(uint8_t PinNumber)
{

}






