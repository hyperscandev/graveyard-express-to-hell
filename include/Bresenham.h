#ifndef BRESENHAM_H
#define BRESENHAM_H

// include required libraries
#include <vector>

//! type alias for readability
typedef std::pair<int, int> Point;

//! ISO C99 implementation of the Bresenham line algorithm
std::vector<Point> bresenham(int x1, int y1, int x2, int y2);
#endif
