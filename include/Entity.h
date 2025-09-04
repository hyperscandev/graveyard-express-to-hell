#ifndef ENTITY
#define ENTITY

class Entity {
	public:
		Entity();
		Entity(const unsigned short x, const unsigned short y, const char* c, const unsigned short int color);
		bool operator<(const Entity& other) const;
		unsigned short int getId() const;
		unsigned short int getPrevX() const;
		unsigned short int getPrevY() const;
		unsigned short int getX() const;
		unsigned short int getY() const;
		void setX(const unsigned short int x);
		void setY(const unsigned short int y);
		const char* getChar() const;
		unsigned short int getColor() const;
		void move(const unsigned int dx, const unsigned int dy);
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
