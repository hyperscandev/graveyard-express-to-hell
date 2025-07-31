/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example was coded by hyperscandev (https://hyperscandev.glitch.me)

This is the basic Hello World! example. It contains the very barebones code necessary to show "Hello World!" on the screen.

*/

#include "tv/tv.h"
#include "../include/Entity.h"
#include "../include/InputHandlers.h"
#include <set>

// constants
const unsigned short int SCREEN_WIDTH = 79;
const unsigned short int SCREEN_HEIGHT = 29;

// Stupid framebuffer for now
unsigned short *fb = (unsigned short *) 0xA0400000;

int main(){
	
	int nExitCode = 0;
	/************************************************************************/
	/*   TODO: add your code here                                           */
	/************************************************************************/

	/*
	 Set TV output up with RGB565 color scheme and make set all framebuffers
	 to stupid framebuffer address, TV_Init will select the first framebuffer
	 as default.
	*/
	tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);

	/*create the player entity */
	Entity player = Entity(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "@", 0);

	// Set of entities
	std::set<Entity> entities;

	// add the player to the entities set
	entities.insert(player);

	// for storing the players previous position
	unsigned short int previous_playerx;
	unsigned short int previous_playery;

	// create instance of event handler
	EventHandler events = EventHandler();

	while(1){
		// get events
		Action* action = events.ev_input();

		// action is a pointer to MovementAction (or derived from it)
		if (dynamic_cast<MovementAction*>(action) != NULL) {
			if (MovementAction* moveAction = dynamic_cast<MovementAction*>(action)) {
				// save the players previous position
				previous_playerx = player.getX();
				previous_playery = player.getY();
				
				// set player's new position
				player.setX(player.getX() + moveAction->getDX());
				player.setY(player.getY() + moveAction->getDY());
			}
		}

		// erase the player from the previous position
		tv_print(fb, previous_playerx, previous_playery, " ");

		// draw the player on the screen
		tv_print(fb, player.getX(), player.getY(), player.getChar());
		
		// delete the pointer
		delete action;
				
	}
		
	return nExitCode;
}
