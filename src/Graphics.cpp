#include "Graphics.h"

Graphics::Graphics()
{
	
}

void Graphics::init() {
	initscr(); /*start curses mode*/
	raw(); /*line buffering disabled*/
	keypad(stdscr, TRUE); // we get F1, F2 etc...
	noecho(); //don't echo while we do getch
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
	werase(local_win);
	wrefresh(local_win);
	delwin(local_win);
}

int Graphics::getNumRow() {
	return _row;
}

int Graphics::getNumCol() {
	return _col;
}

WINDOW * Graphics::create_newwin_samecentre(int height, int width, WINDOW * reference) {
	int row, col;

	getmaxyx(reference, row, col);
	return create_newwin(height, width, (row - height) / 2, (col - width) / 2);
}

void Graphics::printString_relativecentre(vector<string> &str, WINDOW * reference) {
	int row, col;
	int length, width;

	getmaxyx(reference, row, col);
	length = str.size();

	for(int i = 0; i < length; i++) {
		width  = str[i].length();
		mvwprintw(reference, (row - length)/2 + i, (col - width) / 2, "%s", str[i].c_str());
	}
}