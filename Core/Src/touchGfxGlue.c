/*
 * touchGfxGlue.c
 *
 *  Created on: Nov 11, 2022
 *      Author: ber
 */

#include <stdint.h>

#include "SSD1963.h"

void touchgfxSignalVSync(void);

int touchgfxDisplayDriverTransmitActive() {
	return 0;
}

void touchgfxDisplayDriverTransmitBlock(const uint8_t* pixels, uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
	LCD_DispPicSize(x, y, w, h, pixels);
//	uint16_t *data = (uint16_t *)pixels;
//	for (int j = y; j < y+h; j++) {
//		for (int i = x; i < x+w; i++) {
//			//uint16_t data = *pixels | (*(pixels+1) << 8);
//			LCD_PutPixel(i, j, *data);
//			data++;
//
//		}
//	}
//	touchgfxSignalVSync();
	DisplayDriver_TransferCompleteCallback();
//	touchgfx::startNewTransfer();
}

