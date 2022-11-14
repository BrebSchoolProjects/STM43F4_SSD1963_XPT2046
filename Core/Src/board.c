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
	GPIO_InitTypeDef pb5;
	pb5.Alternate = 0;
	pb5.Mode = GPIO_MODE_OUTPUT_PP;
	pb5.Pin = GPIO_PIN_5;
	pb5.Pull = GPIO_NOPULL;
	pb5.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(GPIOB, &pb5);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
}

