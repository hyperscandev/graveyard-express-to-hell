// include the header
#include "../include/Bresenham.h"

/**
 * Bresenham's Line Algorithm:
 * Creates the most accurate representation of a straight line between two points (x1, y1) and (x2, y2) on a raster display.
 * This method eliminates the need for costly floating-point calculations, resulting in a rapid and efficient process.
 * The technique incrementally computes the next pixel to plot using an 'error' term, guiding the decision to move horizontally,
 * vertically, or diagonally to remain true to the intended line.
 *
 * @param x1 x-coordinate of the start point 
 * @param y1 y-coordinate of the start point
 * @param x2 x-coordinate of the end point
 * @param y2 y-coordinate of the end point
 * @return Point vector with x and y coordinates
 */
std::vector<Point> bresenham(int x1, int y1, int x2, int y2) {
	std::vector<Point> points;
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        points.push_back(Point(x1, y1));
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }

    return points;
}
