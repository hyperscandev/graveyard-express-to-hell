#ifndef PROCEDURALGENERATOR_H
#define PROCEDURALGENERATOR_H

// include required libraries
#include "Bresenham.h"
#include "GameMap.h"
#include "RectangularRoom.h"
#include "Tile_Types.h"

//! type definition for a single point
typedef std::pair<int, int> Point;

//! generates a dungeon
GameMap generate_dungeon(unsigned short int map_width, unsigned short int map_height);
//! generates a tunnel between two rooms
std::vector<Point> tunnel_between(const Point &start, const Point &end);
#endif
