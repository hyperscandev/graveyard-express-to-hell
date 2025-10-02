#ifndef RECTANGULARROOM_H
#define RECTANGULARROOM_H

// include required libraries
#include <utility>

class RectangularRoom {
	struct Slice {
    	int start;
    	int end; // exclusive
		Slice(int start, int end) : start(start), end(end) {} // constructor
	};
	
	public:
		RectangularRoom(unsigned short int x, unsigned short int y, unsigned short int width, unsigned short int height);
		std::pair<int, int> center() const;
		std::pair<Slice, Slice> inner() const;
	private:
		unsigned short int x1;
		unsigned short int y1;
		unsigned short int x2;
		unsigned short int y2;
};
#endif
