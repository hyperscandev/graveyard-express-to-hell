#ifndef TERMINAL_H
#define TERMINAL_H

// include retuired libraries
#include "tv/tv.h"

// function prototypes
void tv_printcolorex(unsigned short *fb, unsigned int x, unsigned int y, const char *text, unsigned short fgcolor, unsigned short bgcolor);

#endif
