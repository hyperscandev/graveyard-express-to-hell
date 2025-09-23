// include the header
#include "../include/Engine.h"

unsigned short *fb = (unsigned short *) 0xA0400000;

Engine::Engine(std::set<Entity> entities, EventHandler event_handler, GameMap game_map, Entity player) {
	// assign frabebuffer pointer
	this->fb = (unsigned short *) 0xA0400000;
	// store instance of entities
	this->entities = entities;
	// store instance of event handler
	this->event_handler = event_handler;
	// store instance of game map
	this->game_map = game_map;
	// store instance of player instance
	this->player = player;
	
}

void Engine::handle_events() {
	// get events
	Action* action = this->event_handler.ev_input();

	// action is a pointer to MovementAction (or derived from it)
	if (dynamic_cast<MovementAction*>(action) != NULL) {
		if (MovementAction* moveAction = dynamic_cast<MovementAction*>(action)) {

			// set player's new position
			this->player.move(moveAction->getDX(), moveAction->getDY());
		}
	}
}

void Engine::render() {
	// draw the map
	game_map.render(fb);

	for (std::set<Entity>::iterator it = entities.begin(); it != entities.end(); ++it) {
		Entity entity = *it;
		
		// erase the entity from the previous position
		tv_print(fb, entity.getPrevX(), entity.getPrevY(), " ");

		// draw the entity on the screen
		tv_print(fb, entity.getX(), entity.getY(), entity.getChar());
	}
		// erase the player from the previous position
		tv_print(fb, player.getPrevX(), player.getPrevY(), " ");

		// draw the player on the screen
		tv_print(fb, player.getX(), player.getY(), player.getChar());
}
