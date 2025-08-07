#ifndef ENGINE_H
#define ENGINE_H

// include required libraries
#include "tv/tv.h"
#include "../include/Entity.h"
#include "../include/InputHandlers.h"
#include <set>

class Engine {
	public:
		Engine(std::set<Entity> entities, EventHandler event_handler, Entity player);
		void handle_events();
		void render();
	private:
		unsigned short *fb;				// Stupid framebuffer for now
		std::set<Entity> entities;		// Set of entities
		EventHandler event_handler;		// instance of event handler
		Entity player;					// player entity
};
#endif
