#ifndef PROCEDURALGENERATOR_H
#define PROCEDURALGENERATOR_H

// include required libraries
#include "Bresenham.h"
#include "GameMap.h"
#include "RectangularRoom.h"
#include "Tile_Types.h"

typedef std::pair<int, int> Point;

GameMap generate_dungeon(unsigned short int map_width, unsigned short int map_height);
std::vector<Point> tunnel_between(const Point &start, const Point &end);
#endif
