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
	bool walkable : 1;
	// is tile is transparent?
	bool transparent : 1;
	// glyph of the tile
	unsigned char ch;
	// palette index to dark foreground graphic color of the tile
	unsigned char dark_foreground_palette;
	// palette index to dark background graphic color of the tile
	unsigned char dark_background_palette;
	// palette index to light foreground graphic color of the tile
    unsigned char light_foreground_palette;
    // palette index to light background graphic color of the tile
    unsigned char light_background_palette;
};

//! helper function for defining a new tile
Tile new_tile(const bool walkable, const bool transparent, const unsigned char ch, const unsigned char dark_fg_r, const unsigned char dark_fg_g, const unsigned char dark_fg_b, const unsigned char dark_bg_r, const unsigned char dark_bg_g, const unsigned char dark_bg_b, const unsigned char light_fg_r, const unsigned char light_fg_g, const unsigned char light_fg_b, const unsigned char light_bg_r, const unsigned char light_bg_g, const unsigned char light_bg_b);

//! floor tile definition is defined in source
extern Tile floor_tile;
//! floor wall definition is defined in source
extern Tile wall_tile;
#endif
