#ifndef ENGINE_H
#define ENGINE_H

// include required libraries
#include "tv/tv.h"
#include "../include/Entity.h"
#include "../include/InputHandlers.h"
#include "../include/GameMap.h"
#include <set>

/**
 * Game Engine class
 *
 * handles user input, rendering the game map, player, enemies and items
 */
class Engine {
	public:
		//! class constructor with parameters to hold set of entities, game map and player as well as an instance of the event handler class
		Engine(std::set<Entity> entities, EventHandler event_handler, GameMap game_map, Entity player);
		//! handles user input
		void handle_events();
		//! renders player, entities and game map to the framebuffer
		void render();
	private:
		//! stupid framebuffer for now
		unsigned short *fb;
		//! set of entities
		std::set<Entity> entities;
		//! instance of event handler
		EventHandler event_handler;
		//! instance of game map
		GameMap game_map;
		//! player entity
		Entity player;
};
#endif
