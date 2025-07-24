// include the header
#include "../include/MovementAction.h"

MovementAction::MovementAction(unsigned short dx, unsigned short dy): Action() {
	this->dx = dx;
	this->dy = dy;
}

unsigned short int MovementAction::getDX() {
	return this->dx;
}

unsigned short int MovementAction::getDY() {
	return this->dy;
}
