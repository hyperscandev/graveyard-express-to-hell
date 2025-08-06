#ifndef ENTITY
#define ENTITY

class Entity {
	public:
		Entity();
		Entity(unsigned short x, unsigned short y, const char* c, unsigned short int color);
		bool operator<(const Entity& other) const;
		unsigned short int getId();
		unsigned short int getPrevX();
		unsigned short int getPrevY();
		unsigned short int getX();
		unsigned short int getY();
		void setX(unsigned short int x);
		void setY(unsigned short int y);
		const char* getChar();
		unsigned short int getColor();
		void move(unsigned int dx, unsigned int dy);
	private:
		unsigned short int id;	// Instance-specific ID
		static unsigned short int nextId;	// Static counter for auto-incrementing IDs
		unsigned short int prevX;
		unsigned short int prevY;
		unsigned short int x;
		unsigned short int y;
		const char* c;
		unsigned short int color;
};
#endif
