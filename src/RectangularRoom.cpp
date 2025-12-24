// include the header
#include "../include/RectangularRoom.h"

RectangularRoom::RectangularRoom(unsigned short int x, unsigned short int y, unsigned short int width, unsigned short int height) {
	this->x1 = x;
	this->y1 = y;
	this->x2 = x + width;
	this->y2 = y + height;
}

std::pair<int, int> RectangularRoom::center() const {
	int center_x = ((this->x1 + this->x2) / 2);
    int center_y = ((this->y1 + this->y2) / 2);
    
    return std::make_pair(center_x, center_y);

}

std::pair<RectangularRoom::Slice, RectangularRoom::Slice> RectangularRoom::inner() const {
	return std::make_pair(
		RectangularRoom::Slice( static_cast<int>(x1) + 1, static_cast<int>(x2) ),
		RectangularRoom::Slice( static_cast<int>(y1) + 1, static_cast<int>(y2) )
	);
}

bool RectangularRoom::intersects(RectangularRoom other) const {
	return (this->x1 <= other.x2 && this->x2 >= other.x1 && this->y1 <= other.y2 && this->y2 >= other.y1);
}
