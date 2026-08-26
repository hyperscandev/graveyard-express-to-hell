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
	// light graphic of the tile
	Graphic light;
};

//! helper function for defining a new tile
Tile new_tile(const bool walkable, const bool transparent, const unsigned char ch, const unsigned char dark_fg_r, const unsigned char dark_fg_g, const unsigned char dark_fg_b, const unsigned char dark_bg_r, const unsigned char dark_bg_g, const unsigned char dark_bg_b, const unsigned char light_fg_r, const unsigned char light_fg_g, const unsigned char light_fg_b, const unsigned char light_bg_r, const unsigned char light_bg_g, const unsigned char light_bg_b);

//! SHROUD represents unexplored, unseen tiles
const Graphic SHROUD = {' ', RGB565(255, 255, 255), RGB565(0, 0, 0)};

//! floor tile definition is defined in source
extern Tile floor_tile;
//! floor wall definition is defined in source
extern Tile wall_tile;
#endif
