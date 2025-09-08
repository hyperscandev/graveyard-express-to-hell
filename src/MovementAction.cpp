// include the header
#include "../include/MovementAction.h"

MovementAction::MovementAction(const unsigned short dx, const unsigned short dy): Action() {
	this->dx = dx;
	this->dy = dy;
}

unsigned short int MovementAction::getDX() const {
	return this->dx;
}

unsigned short int MovementAction::getDY() const {
	return this->dy;
}
