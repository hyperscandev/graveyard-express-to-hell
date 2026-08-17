// include the header
#include "../include/ProceduralGenerator.h"

/**
 * Generates a dungeon of a given width and height
 *
 * @param max_room the maxinum number of rooms to attempt to generate
 * @param room_min_size mininum size of the generated room(characters)
 * @param room_max_size maxinum size of the generated room(characters)
 * @param map_width the width of the game map the dungeon will reside
 * @param map_height the height of the game map the dungeon will reside
 * @param player instance of the player entity
 *
 * @return game map instance containing the dungeon
 */
const GameMap generate_dungeon(const unsigned short int max_rooms, const unsigned short int room_min_size, const unsigned short int room_max_size, const unsigned short int map_width, const unsigned short int map_height, Entity &player) {
	// create instance of game map
	GameMap dungeon = GameMap(map_width, map_height);

	// create vector to hold rooms in dungeon
	std::vector<RectangularRoom> rooms;

	for (int r = 0; r < max_rooms; ++r) {
		// generate the rooms width randomly
    	unsigned short int room_width = (std::rand() % (room_max_size - room_min_size + 1)) + room_min_size;

		// generate the rooms height randomly
		unsigned short int room_height = (std::rand() % (room_max_size - room_min_size + 1)) + room_min_size;
		
		// generate the rooms x position randomly
		unsigned short int x = std::rand() % (dungeon.getWidth() - room_width);

		// generate the rooms y position randomly
		unsigned short int y = std::rand() % (dungeon.getHeight() - room_height);

		// "RectangularRoom" class makes rectangles easier to work with
		RectangularRoom new_room(x, y, room_width, room_height);

		// Run through the other rooms and see if they intersect with this one.
		bool intersects_any = false;
		for (std::vector<RectangularRoom>::const_iterator it = rooms.begin(); it != rooms.end(); ++it) {
			if (new_room.intersects(*it)) {
				intersects_any = true;
				break;
			}
		}

		// if the room intersected
		if (intersects_any) {
    		// go to the next attempt
			continue;
    	}

		// fill the new room with floor tiles
		std::pair<RectangularRoom::Slice, RectangularRoom::Slice> inner = new_room.inner();
		for (int x = inner.first.start; x < inner.first.end; ++x) {
			for (int y = inner.second.start; y < inner.second.end; ++y) {
				dungeon.set_tile(x, y, floor_tile);
			}
		}

		// if this is the first room
		if(rooms.size() == 0) {
			player.setX(new_room.center_x());
			player.setY(new_room.center_y());
		// all rooms after the first
		} else {
			// 
			std::vector<Point> path = tunnel_between(rooms.back().center(), new_room.center());

			for (std::vector<Point>::const_iterator it = path.begin(); it != path.end(); ++it) {
				int x = it->first;
				int y = it->second;
				dungeon.set_tile(x, y, floor_tile);
			}
		}

    	// if there are no intersections then the room is valid.
		rooms.push_back(new_room);
	}

	// return the filled in map instance
	return dungeon;
}

/**
 * Generates a tunnel between two rooms
 *
 * @param start the starting point
 * @param end the ending point
 *
 * @return a vector of points that forms a tunnel connecting two rooms
 */
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
