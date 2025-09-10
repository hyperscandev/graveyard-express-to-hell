#ifndef TILE_TYPES_H
#define TILE_TYPES_H

// include required libraries
#include "tv/tv.h"

struct Graphic {
	char ch;
	unsigned short fg;
	unsigned short bg;
};

struct Tile {
	bool walkable;
	bool transparent;
	Graphic dark;
};

// helper functiom
Tile new_tile(const int walkable, const int transparent, const char ch, const int fg_r, const int fg_g, const int fg_b, const int bg_r, const int bg_g, const int bg_b);

extern Tile floor_tile;
extern Tile wall_tile;
#endif
