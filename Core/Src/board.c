/*
 * board.c
 *
 * Helper functions for board setup
 *
 *  Created on: 14.11.2022
 *      Author: ber
 */

#include "stm32f4xx_hal.h"

void setupDefaultGpios(void) {
	// PB5 -> disable on board SDRAM
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef pin;
	pin.Alternate = 0;
	pin.Mode = GPIO_MODE_OUTPUT_PP;
	pin.Pin = GPIO_PIN_5;
	pin.Pull = GPIO_NOPULL;
	pin.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(GPIOB, &pin);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);

	// PC1 -> disable L3GD20 on SPI
	__HAL_RCC_GPIOC_CLK_ENABLE();
	pin.Pin = GPIO_PIN_1;
	HAL_GPIO_Init(GPIOC, &pin);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);

}

