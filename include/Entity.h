#ifndef ENTITY
#define ENTITY

/**
 * Class to represent a single game entity
 */
class Entity {
	public:
		//! default class constructor
		Entity();
		//! full class constructor 
		Entity(const unsigned short x, const unsigned short y, const char* c, const unsigned short int color);
		//! less-than operator overload function
		bool operator<(const Entity& other) const;
		//! returns the instance-specific id
		unsigned short int getId() const;
		//! returns the entity's previous x position
		unsigned short int getPrevX() const;
		//! returns the entity's previous y position
		unsigned short int getPrevY() const;
		//! returns the entity's current x position
		unsigned short int getX() const;
		//! returns the entity's current y position
		unsigned short int getY() const;
		//! sets the entity's x position
		void setX(const unsigned short int x);
		//! sets the entity's y position
		void setY(const unsigned short int y);
		//! gets the entity's character representation
		const char* getChar() const;
		//! gets the entity's character forecolor
		unsigned short int getColor() const;
		//! moves the entity to the given x and y position
		void move(const unsigned int dx, const unsigned int dy);
	private:
		//! Instance-specific ID
		unsigned short int id;
		//! Static counter for auto-incrementing IDs
		static unsigned short int nextId;
		//! previous x position
		unsigned short int prevX;
		//! previous y position
		unsigned short int prevY;
		//! current x position
		unsigned short int x;
		//! current y position
		unsigned short int y;
		//! character representation
		const char* c;
		//! character forecolor
		unsigned short int color;
};
#endif
