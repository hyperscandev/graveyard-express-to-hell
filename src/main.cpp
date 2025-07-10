/*

This is part of the Mattel HyperScan SDK by ppcasm (ppcasm@gmail.com)

This example was coded by hyperscandev (https://hyperscandev.glitch.me)

This is the basic Hello World! example. It contains the very barebones code necessary to show "Hello World!" on the screen.

*/

#include "tv/tv.h"

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

	// set the player's position
	unsigned short int playerx = SCREEN_WIDTH / 2;
	unsigned short int playery = SCREEN_HEIGHT / 2;

	while(1){
				
		// draw the player on the screen
		tv_print(fb, playerx, playery, "@");
				
	}
		
	return nExitCode;
}
