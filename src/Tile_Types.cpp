// include the header
#include "../include/Tile_Types.h"

Tile new_tile(int walkable, int transparent, int ch, int fg_r, int fg_g, int fg_b, int bg_r, int bg_g, int bg_b) {
	Tile tile;
    tile.walkable = walkable;
    tile.transparent = transparent;
    tile.dark.ch = ch;
    tile.dark.fg.r = fg_r;
    tile.dark.fg.g = fg_g;
    tile.dark.fg.b = fg_b;
    tile.dark.bg.r = bg_r;
    tile.dark.bg.g = bg_g;
    tile.dark.bg.b = bg_b;
    return tile;
}
