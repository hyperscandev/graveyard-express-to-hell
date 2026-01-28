#ifndef INPUTHANDLERS
#define INPUTHANDLERS

#include "hyperscan/hs_controller/hs_controller.h"
#include <cstddef>
#include "../include/MovementAction.h"

/**
 * Handles events like getting user input
 */
class EventHandler {
	public:
		//! default class constructor
		EventHandler();
		//! gets user input
		Action* ev_input();
};
#endif
