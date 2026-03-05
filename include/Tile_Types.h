#ifndef TILE_TYPES_H
#define TILE_TYPES_H

// include required libraries
#include "tv/tv.h"

//! struct for a single graphic
struct Graphic {
	// character associated with the graphic
	unsigned char ch;
	// foreground color
	unsigned short fg;
	// background color
	unsigned short bg;
};

//! struct for a single tile
struct Tile {
	// is tile is walkable?
	bool walkable;
	// is tile is transparent?
	bool transparent;
	// dark graphic of the tile
	Graphic dark;
};

//! helper function for defining a new tile
Tile new_tile(const bool walkable, const bool transparent, const unsigned char ch, const unsigned char fg_r, const unsigned char fg_g, const unsigned char fg_b, const unsigned char bg_r, const unsigned char bg_g, const unsigned char bg_b);

//! floor tile definition is defined in source
extern Tile floor_tile;
//! floor wall definition is defined in source
extern Tile wall_tile;
#endif
