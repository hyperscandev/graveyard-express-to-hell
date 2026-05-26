#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "tv/tv.h"
#include "Tile_Types.h"
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
		GameMap(const unsigned int width, const unsigned int height);
		//! returns the maps width
		unsigned int getWidth() const;
		//! returns the maps height
		unsigned int getHeight() const;
		//! sets a tile at a given x/y coordinate
		void set_tile(const unsigned short int x, const unsigned short int y, const Tile& tile);
		//! returns if the given coordinate is inbounds
		bool in_bounds(const unsigned short int x, const unsigned short int y) const;
		//! returns if the tile at the given x/y coordinate is walkable
		bool is_walkable(const unsigned short int x, const unsigned short int y) const;
		//! renders the game map
		void render(unsigned short *fb) const;
	private:
		//! the maps width
		unsigned int width;
		//! the maps height
		unsigned int height;
		//! vector of map tiles
		std::vector<std::vector<Tile> > tiles;
};
#endif
