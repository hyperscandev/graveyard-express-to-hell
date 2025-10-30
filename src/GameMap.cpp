// include the header
#include "../include/GameMap.h"

/**
 * Default Class constructor
 */
 GameMap::GameMap() {
 }

/**
 * Class constructor
 */
 GameMap::GameMap(unsigned int width, unsigned int height) {
 	// set the map width
 	this->width = width;
 	 // set the map height
 	this->height = height;
 	// initalize the 2d array for the map tiles
 	tiles = std::vector<std::vector<Tile> >(width, std::vector<Tile>(height));
 	
 	/** fill the game map entirely with walls; the procedural generator will carve out rooms later */
 	for(unsigned short int x = 0; x < this->width; x++) {
		for(unsigned short int y = 0; y < this->height; y++) {
			tiles[x][y] = wall_tile;
		}
 	}
 }
 
 void GameMap::set_tile(unsigned short int x, unsigned short int y, const Tile& tile) {
    if (x < width && y < height)
        tiles[x][y] = tile;
}
 
/**
 * Returns whether the coordinates are in bounds of the map
 */
bool GameMap::in_bounds(unsigned short int x, unsigned short int y) {
	return (x > 0 && x < this->width && y > 0 && y < this->height);
}

/**
 * Returns whether the tile at the x/y coordinates are walkable
 */
bool GameMap::is_walkable(unsigned short int x, unsigned short int y) {
	return tiles[x][y].walkable;
}

/**
 * Renders the map
 */
void GameMap::render(unsigned short *fb) {
	for(unsigned short int x = 0; x < this->width; x++) {
		for(unsigned short int y = 0; y < this->height; y++) {
			char buffer[2] = { tiles[x][y].dark.ch, '\0' };
			tv_print(fb, x, y, buffer);
		}
	}
}
