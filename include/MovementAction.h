#ifndef MOVEMENTACTION
#define MOVEMENTACTION

#include "Action.h"

class MovementAction: public Action {
	public:
		MovementAction(unsigned short x, unsigned short y);
		unsigned short int getDX();
		unsigned short int getDY();
	private:
		unsigned short int dx;
		unsigned short int dy;
};
#endif
