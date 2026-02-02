// include the header
#include "../include/MovementAction.h"

/**
 * Class constructor with delta x and y parameters
 *
 * @param dx the initial delta x velocity
 * @param dy the initial delta y velocity
 */
MovementAction::MovementAction(const unsigned short dx, const unsigned short dy): Action() {
	this->dx = dx;
	this->dy = dy;
}

/**
 * Returns the delta x velocity
 *
 * @return delta x velocity
 */
unsigned short int MovementAction::getDX() const {
	return this->dx;
}

/**
 * Returns the delta y velocity
 *
 * @return delta y velocity
 */
unsigned short int MovementAction::getDY() const {
	return this->dy;
}
