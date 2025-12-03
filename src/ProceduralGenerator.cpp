// include the header
#include "../include/ProceduralGenerator.h"

GameMap generate_dungeon(unsigned short int map_width, unsigned short int map_height) {
	GameMap dungeon = GameMap(map_width, map_height);

	RectangularRoom room_1 = RectangularRoom(20, 5, 5, 7);
	RectangularRoom room_2 = RectangularRoom(35, 5, 5, 7);

	// --- Fill room_1.inner with floor tiles ---
    std::pair<RectangularRoom::Slice, RectangularRoom::Slice> inner_1 = room_1.inner();
    for (int x = inner_1.first.start; x < inner_1.first.end; ++x) {
        for (int y = inner_1.second.start; y < inner_1.second.end; ++y) {
            dungeon.set_tile(x, y, floor_tile);
        }
    }

    // --- Fill room_2.inner with floor tiles ---
    std::pair<RectangularRoom::Slice, RectangularRoom::Slice> inner_2 = room_2.inner();
    for (int x = inner_2.first.start; x < inner_2.first.end; ++x) {
        for (int y = inner_2.second.start; y < inner_2.second.end; ++y) {
            dungeon.set_tile(x, y, floor_tile);
        }
    }
    
	std::vector<Point> path = tunnel_between(room_2.center(), room_1.center());

	for (std::vector<Point>::const_iterator it = path.begin(); it != path.end(); ++it) {
    	int x = it->first;
    	int y = it->second;
    	dungeon.set_tile(x, y, floor_tile);
	}

	return dungeon;
}

// Tunnel generator function
std::vector<Point> tunnel_between(const Point &start, const Point &end) {
    std::vector<Point> tunnel;

    int x1 = start.first;
    int y1 = start.second;
    int x2 = end.first;
    int y2 = end.second;

    // 50% chance horizontal-first or vertical-first
    bool horizontal_first = (static_cast<float>(std::rand()) / RAND_MAX) < 0.5f;

    int corner_x, corner_y;
    if (horizontal_first) {
        // Move horizontally, then vertically
        corner_x = x2;
        corner_y = y1;
    } else {
        // Move vertically, then horizontally
        corner_x = x1;
        corner_y = y2;
    }

    // First leg
    std::vector<Point> leg1 = bresenham(x1, y1, corner_x, corner_y);
    tunnel.insert(tunnel.end(), leg1.begin(), leg1.end());

    // Second leg
    std::vector<Point> leg2 = bresenham(corner_x, corner_y, x2, y2);
    tunnel.insert(tunnel.end(), leg2.begin(), leg2.end());

    return tunnel;
}
