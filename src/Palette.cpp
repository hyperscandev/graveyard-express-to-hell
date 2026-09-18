// include header
#include "../include/Palette.h"

unsigned short palette[PALETTE_SIZE];

/**
 * initalizes the palette
 */
void init_palette() {
	palette[PAL_BLACK]      = RGB565(0, 0, 0);
	palette[PAL_GREY_DARK]  = RGB565(100, 100, 100);
	palette[PAL_GREY_LIGHT] = RGB565(200, 200, 200);
}
