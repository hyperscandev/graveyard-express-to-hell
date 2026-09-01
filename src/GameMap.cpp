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
 GameMap::GameMap(const unsigned int width, const unsigned int height) {
 	// set the map width
 	this->width = width;
 	 // set the map height
 	this->height = height;
 	// initalize the 2d array for the map tiles
 	tiles = std::vector<std::vector<Tile> >(width, std::vector<Tile>(height));
 	// initalize the 2d array for the map tiles the player sees
 	visible = std::vector<std::vector<bool> >(width, std::vector<bool>(height));
 	// initalize the 2d array for the map tiles the player has seen
 	explored = std::vector<std::vector<bool> >(width, std::vector<bool>(height));
 	
 	/** fill the game map entirely with walls; the procedural generator will carve out rooms later
 	 *  also initalize all tiles the player sees and seen to false 
 	 */
 	for(unsigned short int x = 0; x < this->width; x++) {
		for(unsigned short int y = 0; y < this->height; y++) {
			tiles[x][y] = wall_tile;
			visible[x][y] = false;
			explored[x][y] = false;
		}
 	}
 }

/**
 * Returns the game maps width
 *
 * @return the game maps width
 */
 unsigned int GameMap::getWidth() const {
 	return this->width;
 }
 
 /**
 * Returns the game maps height
 *
 * @return the game maps height
 */
 unsigned int GameMap::getHeight() const {
 	return this->height;
 }

 /**
 * Sets the tile at a given coordinate in the game maap
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param tile the tile to set at the given coordinate
 */
 void GameMap::set_tile(const unsigned short int x, const unsigned short int y, const Tile& tile) {
    if (x < width && y < height)
        tiles[x][y] = tile;
}
 
/**
 * Returns whether the coordinate are in bounds of the map
 *
 * @param x the x coordinate
 * @param y the y coordinate
 *
 * @return true if inbounds, otherwise false
 */
bool GameMap::in_bounds(const unsigned short int x, const unsigned short int y) const {
	return (x > 0 && x < this->width && y > 0 && y < this->height);
}

/**
 * Returns whether the tile at the x/y coordinate are walkable
 *
 * @param x the x coordinate
 * @param y the y coordinate
 *
 * @return true if the tile is walkable, otherwise false
 */
bool GameMap::is_walkable(const unsigned short int x, const unsigned short int y) const {
	return tiles[x][y].walkable;
}

/**
 * returns if the tile at the given x/y coordinate is transparent (i.e. does not block line of sight)
 * note: distinct from walkability - a tile can be transparent but not walkable (e.g. a chasm)
 * or walkable but not transparent (e.g. tall grass)
 *
 * @param x the x coordinate
 * @param y the y coordinate
 *
 * @return true if the tile is transparent, otherwise false
 */
bool GameMap::is_transparent(const unsigned short int x, const unsigned short int y) const {
	return tiles[x][y].transparent;
}

/**
 * computes a field of view from a given radius for the players position
 *
 * @param px the x coordinate of the origin point the field of view is calculated from
 * @param py the y coordinate of the origin point the field of view is calculated from
 * @param radius how many tiles out from (px, py) is visible, in tile units
 */
void GameMap::compute_fov(int px, int py, int radius) {
    int r2 = radius * radius;
    for (int y = py - radius; y <= py + radius; ++y) {
        for (int x = px - radius; x <= px + radius; ++x) {
            if (x < 0 || y < 0) continue; // guard before hitting unsigned params
            if (!in_bounds(static_cast<unsigned short int>(x),
                            static_cast<unsigned short int>(y))) continue;
            int dx = x - px;
            int dy = y - py;
            if (dx * dx + dy * dy > r2) continue; // outside circle
            std::vector<Point> line = bresenham(px, py, x, y);
            for (std::size_t i = 0; i < line.size(); ++i) {
                const Point& p = line[i];
                int lx = p.first;
                int ly = p.second;
                if (!(lx == px && ly == py) &&
                    !is_walkable(static_cast<unsigned short int>(lx),
                                 static_cast<unsigned short int>(ly))) {
                    break; // blocked before reaching target
                }
                visible[ly][lx] = true;
                if (lx == x && ly == y) break; // reached target
            }
        }
    }
}

/**
 * Renders the map
 *
 * @param fb pointer to framebuffer
 */
void GameMap::render(unsigned short *fb) const {
	for(unsigned short int x = 0; x < this->width; x++) {
		for(unsigned short int y = 0; y < this->height; y++) {
			char buffer[2] = { tiles[x][y].dark.ch, '\0' };
			tv_print(fb, x, y, buffer);
		}
	}
}
