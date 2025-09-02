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
Tile new_tile(int walkable, int transparent, char ch, int fg_r, int fg_g, int fg_b, int bg_r, int bg_g, int bg_b);

extern Tile floor_tile;
extern Tile wall_tile;
#endif
