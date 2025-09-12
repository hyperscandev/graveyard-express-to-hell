#ifndef TILE_TYPES_H
#define TILE_TYPES_H

// include required libraries
#include "tv/tv.h"

struct Graphic {
	unsigned char ch;
	unsigned short fg;
	unsigned short bg;
};

struct Tile {
	bool walkable;
	bool transparent;
	Graphic dark;
};

// helper functiom
Tile new_tile(const bool walkable, const bool transparent, const unsigned char ch, const unsigned char fg_r, const unsigned char fg_g, const unsigned char fg_b, const unsigned char bg_r, const unsigned char bg_g, const unsigned char bg_b);

extern Tile floor_tile;
extern Tile wall_tile;
#endif
