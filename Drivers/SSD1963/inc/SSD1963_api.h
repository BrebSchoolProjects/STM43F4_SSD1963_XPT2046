
#ifndef _SSD1963_API_H
#define _SSD1963_API_H

#include <stm32f4xx.h>
#include <stdbool.h>
#include <stdint.h>

/*********************************************************************
* Macros: RGB565CONVERT(red, green, blue)
*
* Overview: Converts true color into 5:6:5 RGB format.
*
* PreCondition: none
*
* Input: Red, Green, Blue components.
*
* Output: 5 bits red, 6 bits green, 5 bits blue color.
*
* Side Effects: none
*
********************************************************************/
#define RGB565CONVERT(red, green, blue) (u16) (((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3))


/*********************************************************************
* Overview: Some basic colors definitions.
*********************************************************************/
// TODO: check color definitions (especially red)
#define BLACK               RGB565CONVERT(0,    0,      0)
#define BRIGHTBLUE          RGB565CONVERT(0,    0,      255)
#define BRIGHTGREEN         RGB565CONVERT(0,    255,    0)
#define BRIGHTCYAN          RGB565CONVERT(0,    255,    255)
#define BRIGHTRED           RGB565CONVERT(255,  0,      0)
#define BRIGHTMAGENTA       RGB565CONVERT(255,  0,      255)
#define BRIGHTYELLOW        RGB565CONVERT(255,  255,    0)
#define BLUE                RGB565CONVERT(0,    0,      128)
#define GREEN               RGB565CONVERT(0,    128,    0)
#define CYAN                RGB565CONVERT(0,    128,    128)
#define RED                 RGB565CONVERT(128,  0,      0)
#define MAGENTA             RGB565CONVERT(128,  0,      128)
#define BROWN               RGB565CONVERT(255,  128,    0)
#define LIGHTGRAY           RGB565CONVERT(128,  128,    128)
#define DARKGRAY            RGB565CONVERT(64,   64,     64)
#define LIGHTBLUE           RGB565CONVERT(128,  128,    255)
#define LIGHTGREEN          RGB565CONVERT(128,  255,    128)
#define LIGHTCYAN           RGB565CONVERT(128,  255,    255)
#define LIGHTRED            RGB565CONVERT(255,  128,    128)
#define LIGHTMAGENTA        RGB565CONVERT(255,  128,    255)
#define YELLOW              RGB565CONVERT(255,  255,    128)
#define WHITE               RGB565CONVERT(255,  255,    255)

#define GRAY0       	    RGB565CONVERT(224,  224,    224)
#define GRAY1         	    RGB565CONVERT(192,  192,    192)
#define GRAY2               RGB565CONVERT(160,  160,    160)
#define GRAY3               RGB565CONVERT(128,  128,    128)
#define GRAY4               RGB565CONVERT(96,   96,     96)
#define GRAY5               RGB565CONVERT(64,   64,     64)
#define GRAY6	            RGB565CONVERT(32,   32,     32)



typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;

typedef int8_t		s8;
typedef int16_t		s16;
typedef int32_t		s32;


u16 Lcd_Color565(u32 RGB);  // RGB��ɫתΪ16λ(565)

typedef union
{
  u16 U16;
  u8 U8[2];
} ColorTypeDef;

void LCD_Text(u16 x, u16 y, u8 *str, u16 len,u16 Color, u16 bkColor);
void LCD_Line(u16 x0, u16 y0, u16 x1, u16 y1,u16 color);
void LCD_Circle(u16 cx,u16 cy,u16 r,u16 color,u8 fill); 
void LCD_Rectangle(u16 left, u16 top, u16 right, u16 bottom, u16 color, bool fill);
void LCD_Square(u16 x0, u16 y0, u16 width, u16 color,u8 fill);
void LCD_ClearCharBox(u16 x,u16 y,u16 color);

void LCD_DispPic_FullSize(const unsigned char *str);
void LCD_DispPic(u16 x0, u16 y0, const unsigned char *str);



#endif // _SSD1963_API_H
