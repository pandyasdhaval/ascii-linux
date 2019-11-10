#pragma once

#include<ncurses.h>
#include<string>
#include<vector>
using namespace std;

class Graphics
{
public:
	Graphics();

	void init();
	WINDOW *create_newwin(int height, int width, int starty, int startx);
	WINDOW *create_newwin_samecentre(int height, int width, WINDOW * reference);

	void printString_relativecentre(vector<string> &str, WINDOW * reference);

	void destroy_win(WINDOW *local_win);

	int getNumRow();
	int getNumCol();
private:
	int _row;
	int _col;
};