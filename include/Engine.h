#ifndef ENGINE_H
#define ENGINE_H

// include required libraries
#include "tv/tv.h"
#include "../include/Entity.h"
#include "../include/InputHandlers.h"
#include "../include/GameMap.h"
#include <set>

class Engine {
	public:
		Engine(std::set<Entity> entities, EventHandler event_handler, GameMap game_map, Entity player);
		void handle_events();
		void render();
	private:
		unsigned short *fb;				// Stupid framebuffer for now
		std::set<Entity> entities;		// Set of entities
		EventHandler event_handler;		// instance of event handler
		GameMap game_map;				// instance of game map
		Entity player;					// player entity
};
#endif
