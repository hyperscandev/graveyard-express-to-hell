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
Tile new_tile(const bool walkable, const bool transparent, const unsigned char ch, const unsigned char dark_fg, const unsigned char dark_bg, const unsigned char light_fg, const unsigned char light_bg) {
	Tile tile;
    tile.walkable = walkable;
    tile.transparent = transparent;
    tile.ch = ch;
    tile.dark.fg = dark_fg;
    tile.dark.bg = dark_bg;
    tile.light.fg = light_fg;
    tile.light.bg = light_bg;
    return tile;
}

//! floor tile definition
Tile floor_tile = new_tile(
    true, // walkable
    true, // transparent
    '.', // character code
    PAL_GREY_DARK, // dark fg grey
    PAL_BLACK, // dark bg black
    PAL_GREY_LIGHT, // light fg grey
    PAL_BLACK // light bg black
);

//! wall tile definition
Tile wall_tile = new_tile(
    false, // walkable
    false, // transparent
    '#', // character code
    PAL_GREY_DARK, // dark fg grey
    PAL_BLACK, // dark bg black
    PAL_GREY_LIGHT, // light fg grey
    PAL_BLACK // light bg black
);
