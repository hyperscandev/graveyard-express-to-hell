#ifndef TILE_TYPES_H
#define TILE_TYPES_H

struct RGB {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct Graphic {
	char ch;
	RGB fg;
	RGB bg;
};

struct Tile {
	bool walkable;
	bool transparent;
	Graphic dark;
};

// helper functiom
Tile new_tile(int walkable, int transparent, int ch, int fg_r, int fg_g, int fg_b, int bg_r, int bg_g, int bg_b);
#endif
