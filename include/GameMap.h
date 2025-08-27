#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "tv/tv.h"
#include "../include/Tile_Types.h"
#include <vector>

class GameMap {
	public:
		GameMap(unsigned int width, unsigned int height);
		bool in_bounds(unsigned short int x, unsigned short int y);
		void render(unsigned short *fb);
	private:
		unsigned int width;
		unsigned int height;
		std::vector<std::vector<Tile> > tiles;
};
#endif
