#ifndef MOVEMENTACTION
#define MOVEMENTACTION

#include "Action.h"

class MovementAction: public Action {
	public:
		MovementAction(const unsigned short x, const unsigned short y);
		unsigned short int getDX() const;
		unsigned short int getDY() const;
	private:
		unsigned short int dx;
		unsigned short int dy;
};
#endif
