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

	return dungeon;
}
