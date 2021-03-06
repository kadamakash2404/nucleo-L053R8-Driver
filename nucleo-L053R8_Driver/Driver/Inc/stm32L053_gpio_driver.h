/*
 * stm32L053_gpio_driver.h
 *
 *  Created on: 22-Feb-2022
 *      Author: kadam
 */

#ifndef INC_STM32L053_GPIO_DRIVER_H_
#define INC_STM32L053_GPIO_DRIVER_H_
#include "STM32L053xx.h"


typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;					/*<@GPIO_PIN_MODES>*/
	uint8_t GPIO_PinSpeed;					/*<@GPIO_PIN_SPEED>*/
	uint8_t GPIO_PinPuPdControl;			/*<@GPIO_PIN_PUPD_CONFIG>*/
	uint8_t GPIO_PinOPType;					/*<@GPIO_PIN_OUTPUT_TYPE>*/
	uint8_t GPIO_PinAltFunMode;


}GPIO_PinConfig_t;





typedef struct
{
	// pointer to hold the base address of gpio peripheral

	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;




/*
 * GPIO_PIN_NUMBER
 * possible gpio pin number
 */

#define GPIO_PIN_0				0
#define GPIO_PIN_1				1
#define GPIO_PIN_2				2
#define GPIO_PIN_3				3
#define GPIO_PIN_4				4
#define GPIO_PIN_5				5
#define GPIO_PIN_6				6
#define GPIO_PIN_7				7
#define GPIO_PIN_8				8
#define GPIO_PIN_9				9
#define GPIO_PIN_10				10
#define GPIO_PIN_11				11
#define GPIO_PIN_12				12
#define GPIO_PIN_13				13
#define GPIO_PIN_14				14
#define GPIO_PIN_15				15




/*
 * GPIO_PIN_MODES
 * GPIO possible pin modes
 */
#define GPIO_MODE_IN			0
#define GPIO_MODE_OUT			1
#define GPIO_MODE_ALTFUN		2
#define GPIO_MODE_ANALOG		3
#define GPIO_MODE_IT_FT			4
#define GPIO_MODE_IT_RT			5
#define GPIO_MODE_IT_RFT		6



/*
 * GPIO_PIN_OUTPUT_TYPE
 * GPIO possible output types
 */

#define GPIO_OP_TYPE_PP			0
#define GPIO_OP_TYPE_OD			1



/*
 * GPIO_PIN_SPEED
 * GPIO PIN POSSIBLE OUTPUT SPEED
 */

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_HIGH			2
#define GPIO_SPEED_VERY_HIGH	3


/*
 * GPIO_PIN_PUPD_CONFIG
 * GPIO pin pull up and pull down configuration
 */

#define GPIO_PIN_NO_PUPD			0
#define GPIO_PIN_PU					1
#define GPIO_PIN_PD					2




/************************************************************************************
 * 				APIs supported by this driver
 * 		For more information about the APIs check the function definition
 ***********************************************************************************/



/*
 * peripheral clock setup
 */
void GPIO_PeriClkControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and DeInit
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/*
 *  Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void Gpio_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * IRQ configuration and handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);





#endif /* INC_STM32L053_GPIO_DRIVER_H_ */
