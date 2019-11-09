#include "Graphics.h"

Graphics::Graphics()
{
}

WINDOW *Graphics::create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0); // 0, 0 gives default characters for horizontal and vertical lines
	wrefresh(local_win); // show that box
	return local_win; 
}

void Graphics::destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}