// include the header
#include "../include/Terminal.h"

/**
 *
 * This prints text to the selected TV framebuffer with the requested foreground and background color
 *
 * @param fb pointer to framebuffer
 * @parm x x position of text
 * @parm y y position of text
 * @param text to draw
 * @param fgcolor foreground color
 * @parm bgcolor background color
 */
void tv_printcolorex(unsigned short *fb, unsigned int x, unsigned int y, const char *text, unsigned short fgcolor, unsigned short bgcolor){
	short xx, yy;

	while (*text) {
		for (yy = 0; yy < 16; yy++) {
            for (xx = 0; xx < 8; xx++) {
            	// Check the bit in the font
            	if (font[(*text) * 16 + yy] & (1 << (8 - xx))) {
            		// Foreground pixel
            		fb[(y * 16 + yy) * 640 + (x * 8 + xx)] = fgcolor;
            	} else {
            		// Background pixel
            		fb[(y * 16 + yy) * 640 + (x * 8 + xx)] = bgcolor;
            	}
            }
		}
		x++;
		text++;
	}
}
