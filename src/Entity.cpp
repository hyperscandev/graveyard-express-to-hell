// include the header
#include "../include/Entity.h"

// holds the next id to assign
unsigned short int Entity::nextId = 0;

/**
 * Default class constructor
 */
Entity::Entity() {
}

/**
 * Full class constructor
 *
 * @param x the initial x-coordinate of the entity
 * @param y the initial y-coordinate of the entity
 * @param c the character representation of the entity
 * @param color the forecolor of the entity
 */
Entity::Entity(const unsigned short x, const unsigned short y, const char* c, const unsigned short int color): id(++nextId) {
	this->x = x;
	this->y = y;
	this->c = c;
	this->color = color;
}

/**
 * less-than operator overload
 *
 * @param other the other entity to compare to
 * @return true if the entity should come before other in a sorted sequence, otherwise false
 */
bool Entity::operator<(const Entity& other) const {
        return this->id < other.id;
}

/**
 * Returns the id assigned to the entity
 *
 * @return the id assigned to the entity
 */
unsigned short int Entity::getId() const {
	return this->id;
}

/**
 * Returns the previous x position of the entity
 *
 * @return the previous x position of the entity
 */
unsigned short int Entity::getPrevX() const {
	return this->prevX;
}

/**
 * Returns the previous y position of the entity
 *
 * @return the previous y position of the entity
 */
unsigned short int Entity::getPrevY() const {
	return this->prevY;
}

/**
 * Returns the current x position of the entity
 *
 * @return the current x position of the entity
 */
unsigned short int Entity::getX() const {
	return this->x;
}

/**
 * Returns the current y position of the entity
 *
 * @return the current y position of the entity
 */
unsigned short int Entity::getY() const {
	return this->y;
}

/**
 * Returns the character representation of the entity
 *
 * @return the character representation of the entity
 */
const char* Entity::getChar() const {
	return this->c;
}

/**
 * Returns the forecolor of the entity
 *
 * @return the forecolor of the entity
 */
unsigned short int Entity::getColor() const {
	return this->color;
}

/**
 * Sets the x position of the entity
 *
 * @param y the new x position of the entity
 */
void Entity::setX(const unsigned short int x) {
	this->x = x;
}

/**
 * Sets the y position of the entity
 *
 * @param y the new x position of the entity
 */
void Entity::setY(const unsigned short int y) {
	this->y = y;
}

/**
 * Moves the entity to a given x and y coordinate
 *
 * @param dx the new delta x coordinate
 * @param dy the new delta y coordinate
 */
void Entity::move(const unsigned int dx, const unsigned int dy) {
	this->prevX = this->x;
	this->x += dx;
	this->prevY = this->y;
	this->y += dy;
}
