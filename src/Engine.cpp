// include the header
#include "../include/Engine.h"

//! framebuffer address
unsigned short *fb = (unsigned short *) 0xA0400000;

/**
 * full class constructor
 *
 * @param entities set of entities to update and render
 * @param event_handler instance of event handler
 * @param game_map instance of game map
 * @param player instance of player entity
 */
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

/**
 * handles user input
 */
void Engine::handle_events() {
	// get events
	Action* action = this->event_handler.ev_input();

	// action is a pointer to MovementAction (or derived from it)
	if (dynamic_cast<MovementAction*>(action) != NULL) {
		if (MovementAction* moveAction = dynamic_cast<MovementAction*>(action)) {

			// if the tile is walkable
			if(game_map.is_walkable(player.getX() + moveAction->getDX(), player.getY() + moveAction->getDY())) {

				// set player's new position
				this->player.move(moveAction->getDX(), moveAction->getDY());
			}
		}
	}
}

/**
 * renders the game map, entities and player to the framebuffer(screen)
 */
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
