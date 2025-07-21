#ifndef INPUTHANDLERS
#define INPUTHANDLERS

#include "hyperscan/hs_controller/hs_controller.h"
#include <cstddef>
#include "../include/MovementAction.h"

class EventHandler {
	public:
		EventHandler();
		Action* ev_input();
};
#endif
