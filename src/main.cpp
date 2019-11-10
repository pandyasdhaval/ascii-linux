#include<iostream>
#include "GameSystem.h"
#include "Graphics.h"
#include<fstream>
#include<vector>

#include<string>
using namespace std;

void help(string fileName);
void default_msg(WINDOW *someWindow);

int main()
{
	bool win = true;
	bool exit = false;
	int i = 0;
	
	char choice;


	Graphics myGraphics;
	WINDOW *myWindow;

	int row, col;
	string str;


	myGraphics.init();

	GameSystem gameSystem;

	getmaxyx(stdscr, row, col); // get the number of rows and columns

	printw("This screen has %d rows and %d columns\n", row, col);
	refresh();


	vector<string> messages;

	while (win && !exit) {

		myWindow = myGraphics.create_newwin_samecentre(20, 20, stdscr);

		str = "1. Play Game";
		messages.push_back(str);

		str = "2. Help!";
		messages.push_back(str);

		myGraphics.printString_relativecentre(messages, myWindow);
		messages.clear();

		wrefresh(myWindow);
		
		choice = getch();
		
		myGraphics.destroy_win(myWindow);
		refresh();
		
		switch (choice)
		{
		case '1':
			while (win && i < gameSystem.sizeNumFile())
			{
				i++;
				gameSystem.lvlLoad(i);
				win = gameSystem.playGame();

			}

			if (win)
			{
				myWindow = myGraphics.create_newwin_samecentre(20, 80, stdscr);
		

				str = "Congrats! You won the Game!!!";
				messages.push_back(str);
				myGraphics.printString_relativecentre(messages, myWindow);
				wrefresh(myWindow);

				str.clear();

				getchar();
				myGraphics.destroy_win(myWindow);
				return 0;
			}

			break;
		case '2':

			help("environment/Help.txt");
			break;
		case 'q':
		case 'Q':
			exit = true;
			break;
		default:

			break;
		}
	}
	myWindow = nullptr;
	endwin();
}
void help(string fileName)
{
	ifstream file;
	string buffer;
	
	vector<string> myStr;

	int length = 0;
	unsigned int max = 0;

	Graphics someGraphics;
	WINDOW *someWindow;

	file.open(fileName.c_str());
	if (file.fail())
	{
		perror(fileName.c_str());

		getchar();
		exit(1);
	}
	
	while(!file.eof()) {
		getline(file, buffer);
		myStr.push_back(buffer);
		length++;

		if(buffer.length() > max) {
			max = buffer.length();
		}
		buffer.clear();
	}
	length += 2;
	max += 2;

	someWindow = someGraphics.create_newwin_samecentre(length, max, stdscr);

	someGraphics.printString_relativecentre(myStr, someWindow);

	getmaxyx(someWindow, length, max);
	mvwprintw(someWindow, length - 2, 1, "Any key: ");
	wrefresh(someWindow);
	getch();

	
	someGraphics.destroy_win(someWindow);
	refresh();

	file.close();
}
