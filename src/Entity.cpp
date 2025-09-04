// include the header
#include "../include/Entity.h"

// holds the next id to assign
unsigned short int Entity::nextId = 0;


Entity::Entity() {
}

Entity::Entity(const unsigned short x, const unsigned short y, const char* c, const unsigned short int color): id(++nextId) {
	this->x = x;
	this->y = y;
	this->c = c;
	this->color = color;
}

bool Entity::operator<(const Entity& other) const {
        return this->id < other.id;
}

unsigned short int Entity::getId() const {
	return this->id;
}

unsigned short int Entity::getPrevX() const {
	return this->prevX;
}

unsigned short int Entity::getPrevY() const {
	return this->prevY;
}

unsigned short int Entity::getX() const {
	return this->x;
}

unsigned short int Entity::getY() const {
	return this->y;
}

const char* Entity::getChar() const {
	return this->c;
}

unsigned short int Entity::getColor() const {
	return this->color;
}

void Entity::setX(const unsigned short int x) {
	this->x = x;
}

void Entity::setY(const unsigned short int y) {
	this->y = y;
}

void Entity::move(const unsigned int dx, const unsigned int dy) {
	this->prevX = this->x;
	this->x += dx;
	this->prevY = this->y;
	this->y += dy;
}
