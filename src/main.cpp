/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example was coded by hyperscandev (https://hyperscandev.glitch.me)

This is the basic Hello World! example. It contains the very barebones code necessary to show "Hello World!" on the screen.

*/

#include "tv/tv.h"
#include "../include/ProceduralGenerator.h"
#include "../include/Entity.h"
#include "../include/InputHandlers.h"
#include "../include/Engine.h"
#include <set>

// constants
const unsigned short int SCREEN_WIDTH = 79;
const unsigned short int SCREEN_HEIGHT = 29;
const unsigned short int MAP_WIDTH = 79;
const unsigned short int MAP_HEIGHT = 24;


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

	// Set of entities
	std::set<Entity> entities;

	// create instance of event handler
	EventHandler events = EventHandler();

	/*create the player entity */
	Entity player = Entity(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 5, "@", 0);

	/* create a dungeon */
	GameMap game_map = generate_dungeon(MAP_WIDTH, MAP_HEIGHT);

	// create instance of the game engine
	Engine engine = Engine(entities, events, game_map, player);

	while(1){
		// render the screen
		engine.render();

		// get events
		engine.handle_events();
	}
		
	return nExitCode;
}
