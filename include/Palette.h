#ifndef PALETTE_H
#define PALETTE_H

#include "tv/tv.h"

// size of the global color palette
#define PALETTE_SIZE 32

// global color table, populated by init_palette() at startup
extern unsigned short palette[PALETTE_SIZE];

// named palette slots — add more as you need new colors
enum PaletteIndex {
	PAL_BLACK = 0,
	PAL_GREY_DARK,
	PAL_GREY_LIGHT,
	PAL_COUNT
};

//! populates palette[] with actual RGB565 values; call once at startup
void init_palette();

#endif