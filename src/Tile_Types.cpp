// include the header
#include "../include/Tile_Types.h"

/**
 * Helper function for creating new Tile definitions
 *
 * @param is the tile walkable
 * @param is the tile transparent
 * @param ch character for the tile
 * @param dark_fg_r intensitiy of red primary for dark foreground
 * @param dark_fg_g intensitiy of green primary for dark foreground
 * @param dark_fg_b intensitiy of blue primary for dark foreground
 * @param dark_bg_r intensitiy of red primary for dark background
 * @param dark_bg_g intensitiy of green primary for dark background
 * @param dark_bg_b intensitiy of blue primary for dark background
  * @param light_fg_r intensitiy of red primary for light foreground
 * @param light_fg_g intensitiy of green primary for light foreground
 * @param light_fg_b intensitiy of blue primary for light foreground
 * @param light_bg_r intensitiy of red primary for light background
 * @param light_bg_g intensitiy of green primary for light background
 * @param light_bg_b intensitiy of blue primary for light background
 *
 * @return new Tile struct
 */
Tile new_tile(const bool walkable, const bool transparent, const unsigned char ch, const unsigned char dark_fg_r, const unsigned char dark_fg_g, const unsigned char dark_fg_b, const unsigned char dark_bg_r, const unsigned char dark_bg_g, const unsigned char dark_bg_b, const unsigned char light_fg_r, const unsigned char light_fg_g, const unsigned char light_fg_b, const unsigned char light_bg_r, const unsigned char light_bg_g, const unsigned char light_bg_b) {
	Tile tile;
    tile.walkable = walkable;
    tile.transparent = transparent;
    tile.dark.ch = ch;
    tile.dark.fg = RGB565(dark_fg_r, dark_fg_g, dark_fg_b);
    tile.dark.bg = RGB565(dark_bg_r, dark_bg_g, dark_bg_b);
    tile.light.fg = RGB565(light_fg_r, light_fg_g, light_fg_b);
    tile.light.bg = RGB565(light_bg_r, light_bg_g, light_bg_b);
    return tile;
}

//! floor tile definition
Tile floor_tile = new_tile(
    true, // walkable
    true, // transparent
    '.', // character code
    100, 100, 100, // dark fg grey
    0, 0, 0, // dark bg black
    200, 200, 200, // light fg grey
    0, 0, 0 // light bg black
);

//! wall tile definition
Tile wall_tile = new_tile(
    false, // walkable
    false, // transparent
    '#', // character code
    100, 100, 100, // dark fg grey
    0, 0, 0, // dark bg black
    200, 200, 200, // light fg grey
    0, 0, 0 // light bg black
);
