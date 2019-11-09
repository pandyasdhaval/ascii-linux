#pragma once

#include<ncurses.h>
#include<string>
using namespace std;

class Graphics
{
public:
	Graphics();

	WINDOW *create_newwin(int height, int width, int starty, int startx);
	void destroy_win(WINDOW *local_win);
};