// include the header
#include "../include/Tile_Types.h"

Tile new_tile(int walkable, int transparent, char ch, int fg_r, int fg_g, int fg_b, int bg_r, int bg_g, int bg_b) {
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

Tile floor_tile = new_tile(
    true, // walkable
    true, // transparent
    '.', // character code
    255, 255, 255, // fg white
    50, 50, 150    // bg black
);

Tile wall_tile = new_tile(
    false, // walkable
    false, // transparent
    ' ', // character code
    255, 255, 255, // fg white
    0, 0, 100      // bg black
);
