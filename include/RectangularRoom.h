#ifndef RECTANGULARROOM_H
#define RECTANGULARROOM_H

// include required libraries
#include <utility>

/**
 * class for a handling a single room instance
 */
class RectangularRoom {

	public:
	//! struct for a slice of the room
		struct Slice {
			// start of the room slice exclusive
    		int start;
    		// end of the room slice exclusive
    		int end;
    		//! constructor
			Slice(int start, int end) : start(start), end(end) {}
		};

		//! class constructor with parameters for the starting position (x, y), width and height.
		RectangularRoom(unsigned short int x, unsigned short int y, unsigned short int width, unsigned short int height);
		//! returns the center point of the room
		std::pair<int, int> center() const;
		//! returns the inner area of the room
		std::pair<Slice, Slice> inner() const;
		//! returns if the room intersects another
		bool intersects(RectangularRoom other) const;
	private:
		//! x starting point
		unsigned short int x1;
		//! y starting point
		unsigned short int y1;
		//! x ending point
		unsigned short int x2;
		//! y ending point
		unsigned short int y2;
};
#endif
