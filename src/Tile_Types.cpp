// include the header
#include "../include/Tile_Types.h"

/**
 * Helper function for creating new Tile definitions
 *
 * @param walkable is the tile walkable
 * @param transparent is the tile transparent
 * @param ch character for the tile
 * @param dark_fg palette index for dark-state foreground color
 * @param dark_bg palette index for dark-state background color
 * @param light_fg palette index for light-state foreground color
 * @param light_bg palette index for light-state background color
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
