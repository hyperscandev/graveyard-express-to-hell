#ifndef MOVEMENTACTION
#define MOVEMENTACTION

#include "Action.h"

/**
* class for handling the player's movement
*/
class MovementAction: public Action {
	public:
		//! class constructor with delta x and y velocities 
		MovementAction(const unsigned short x, const unsigned short y);
		//! returns the x delta
		unsigned short int getDX() const;
		//! returns the y delta
		unsigned short int getDY() const;
	private:
		//! the x delta
		unsigned short int dx;
		//! the y delta
		unsigned short int dy;
};
#endif
