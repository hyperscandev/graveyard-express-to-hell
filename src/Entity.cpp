// include the header
#include "../include/Entity.h"

// holds the next id to assign
unsigned short int Entity::nextId = 0;


Entity::Entity() {
}

Entity::Entity(unsigned short x, unsigned short y, const char* c, unsigned short int color): id(++nextId) {
	this->x = x;
	this->y = y;
	this->c = c;
	this->color = color;
}

bool Entity::operator<(const Entity& other) const {
        return this->id < other.id;
}

unsigned short int Entity::getId() {
	return this->id;
}

unsigned short int Entity::getPrevX() {
	return this->prevX;
}

unsigned short int Entity::getPrevY() {
	return this->prevY;
}

unsigned short int Entity::getX() {
	return this->x;
}

unsigned short int Entity::getY() {
	return this->y;
}

const char* Entity::getChar() {
	return this->c;
}

unsigned short int Entity::getColor() {
	return this->color;
}

void Entity::setX(unsigned short int x) {
	this->x = x;
}

void Entity::setY(unsigned short int y) {
	this->y = y;
}

void Entity::move(unsigned int dx, unsigned int dy) {
	this->prevX = this->x;
	this->x += dx;
	this->prevY = this->y;
	this->y += dy;
}
