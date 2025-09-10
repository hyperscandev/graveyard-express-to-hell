// include the header
#include "../include/Tile_Types.h"

Tile new_tile(const int walkable, const int transparent, const char ch, const int fg_r, const int fg_g, const int fg_b, const int bg_r, const int bg_g, const int bg_b) {
	Tile tile;
    tile.walkable = walkable;
    tile.transparent = transparent;
    tile.dark.ch = ch;
    tile.dark.fg = RGB565(fg_r, fg_g, fg_b);
    tile.dark.bg = RGB565(bg_r, bg_g, bg_b);
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
