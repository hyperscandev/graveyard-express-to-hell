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

/**
 * Move's an entity based on it's x and y delta velocity
 *
 * @param engine instance of the game engine
 * @param entity the entity to move
 */
void MovementAction::perform(Engine engine, Entity entity) {
	unsigned short int dest_x = entity.getX() + this->dx;
	unsigned short int dest_y = entity.getY() + this->dy;

	if (engine.getGameMapInstance().in_bounds(dest_x, dest_y)) {
		return;
	}

	if (engine.getGameMapInstance().is_walkable(dest_x, dest_y)) {
		return;
	}

	entity.move(this->dx, this->dy);
}
