// include the header
#include "../include/InputHandlers.h"

EventHandler::EventHandler(){
	/* Initalize Mattel HyperScan controller interface */
	hs_controller_init();
}

Action* EventHandler::ev_input() {
 
	// read the controller
	hs_controller_read();

	/* if the dpad was pressed up */
	if(controller[hs_controller_1].input.joystick_y >= 0xB0){
		return new MovementAction(0, -1);
	}

	/* if the dpad was pressed down */
	if(controller[hs_controller_1].input.joystick_y <= 0x60){
		return new MovementAction(0, 1);
	}

	/* if the dpad was pressed left */
	if(controller[hs_controller_1].input.joystick_x >= 0xB0){
		return new MovementAction(-1, 0);
	}

	/* if the dpad was pressed right */
	if(controller[hs_controller_1].input.joystick_x <= 0x60){
		return new MovementAction(1, 0);
	}

	// no input
	return NULL;
}
