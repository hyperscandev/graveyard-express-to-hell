#ifndef TILE_TYPES_H
#define TILE_TYPES_H

// include required libraries
#include "tv/tv.h"
#include "Palette.h"

//! struct for a single graphic
struct Graphic {
	// index into plalette[] for foreground color
	unsigned char fg;
	// index into plalette[] for background color
	unsigned char bg;
};

//! struct for a single tile
struct Tile {
	// is tile is walkable?
	bool walkable : 1;
	// is tile is transparent?
	bool transparent : 1;
	// glyph of the tile
	unsigned char ch;
	// dark foreground color of the tile
	Graphic dark;
	// light foreground color of the tile
    Graphic light;
};

//! helper function for defining a new tile
Tile new_tile(const bool walkable, const bool transparent, const unsigned char ch, const unsigned char dark_fg, const unsigned char dark_bg, const unsigned char light_fg, const unsigned char light_bg);

//! floor tile definition is defined in source
extern Tile floor_tile;
//! floor wall definition is defined in source
extern Tile wall_tile;
#endif
