#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "tv/tv.h"
#include "../include/Tile_Types.h"
#include <vector>

/**
 * Game Map class
 *
 * handles rendering the game map, players, enemies and objects
 */
class GameMap {
	public:
		//! class constructor
		GameMap();
		//! class constructor with parameters to define it's width and height
		GameMap(unsigned int width, unsigned int height);
		//! returns the maps width
		unsigned int getWidth() const;
		//! returns the maps height
		unsigned int getHeight() const;
		//! sets a tile at a given x/y coordinate
		void set_tile(unsigned short int x, unsigned short int y, const Tile& tile);
		//! returns if the given coordinate is inbounds
		bool in_bounds(unsigned short int x, unsigned short int y);
		//! returns if the tile at the given x/y coordinate is walkable
		bool is_walkable(unsigned short int x, unsigned short int y);
		//! renders the game map
		void render(unsigned short *fb);
	private:
		//! the maps width
		unsigned int width;
		//! the maps height
		unsigned int height;
		//! vector of map tiles
		std::vector<std::vector<Tile> > tiles;
};
#endif
