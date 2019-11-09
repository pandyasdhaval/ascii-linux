#include<iostream>
#include "GameSystem.h"
#include "Graphics.h"
#include<fstream>

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
	initscr(); /*start curses mode*/
	raw(); /*line buffering disabled*/
	keypad(stdscr, TRUE); // we get F1, F2 etc...
	noecho(); //don't echo while we do getch

	GameSystem gameSystem;

	getmaxyx(stdscr, row, col); // get the number of rows and columns

	printw("This screen has %d rows and %d columns\n", row, col);
	refresh();



	while (win && !exit) {

		getmaxyx(stdscr, row, col);
		myWindow = myGraphics.create_newwin(20, 20, row/2 - 10, col/2-10);
		//wrefresh(myWindow);
		str = "1. Play Game";

		getmaxyx(myWindow, row, col);
		mvwprintw(myWindow, row/2 - 1, (col - str.length())/2, "%s", str.c_str());
		
		//wrefresh(myWindow);
		str = "2. Help!";
		mvwprintw(myWindow, row/2, (col - str.length())/2, "%s", str.c_str());
		wrefresh(myWindow);
		
		choice = getch();
		
		myGraphics.destroy_win(myWindow);
		refresh();
		
		//endwin();
		//cout << "1. Play Game\n2. Help!\n";
		//cin >> choice;
		//printf("The choice is %d\n", choice);
		switch (choice)
		{
		case '1':
			//endwin();
			while (win && i < gameSystem.sizeNumFile())
			{
				i++;
				gameSystem.lvlLoad(i);
				win = gameSystem.playGame();

			}

			if (win)
			{
				cout << "Congrats! You won the Game!!!\n";
				system("Pause");
				return 0;
			}

			break;
		case '2':
			//WINDOW aWindow;
			help("Help.txt");
			break;
		case 'q':
		case 'Q':
			exit = true;
			break;
		default:
			//default_msg(myWindow); // myWindow has been destroyed already
			//cout << "Wrong Choice!!!";
			//system("Pause");
			//exit(99);
			break;
		}
	}
	endwin();
}
void help(string fileName)
{
	ifstream file;
	string buffer;
	
	int length = 0;
	unsigned int max = 0;
	int row;
	int col;

	int i = 1;
	int j = 1;

	Graphics someGraphics;
	WINDOW *someWindow;

	file.open(fileName.c_str());
	if (file.fail())
	{
		perror(fileName.c_str());
		system("Pause");
		exit(1);
	}
	
	//cout << "\n\n";
	while(!file.eof()) {
		getline(file, buffer);
		length++;

		if(buffer.length() > max) {
			max = buffer.length();
		}
		buffer.clear();
	}
	max += 2;
	
	file.clear();
	file.seekg(0, ios::beg);

	getmaxyx(stdscr, row, col);

	someWindow = someGraphics.create_newwin(length, max, (row - length)/2, (col - max)/2);
	//wrefresh(someWindow);

	while(!file.eof()) {
		getline(file, buffer);
		mvwprintw(someWindow, i, j, "%s",buffer.c_str());
		i++;
		//waddstr(someWindow, buffer.c_str());
		//waddstr(someWindow, "\n");
		wrefresh(someWindow);
	}
	wprintw(someWindow, "Press any key: ");
	getch();
	wrefresh(someWindow);

	
	someGraphics.destroy_win(someWindow);
	refresh();
	//cout << "\n\n";
	file.close();
}

void default_msg(WINDOW *someWindow) {
	int row, col;
	Graphics someGraphics;
	//WINDOW *someWindow;

	getmaxyx(someWindow, row, col);

	//someWindow = someGraphics.create_newwin(20, 20, (row - 20)/2, (col - 20)/2);
	mvwprintw(someWindow, row - 2, 1, "Wrong Choice!!!");
	mvwprintw(someWindow, row - 1, 1, "Choose Again? ");
	wrefresh(someWindow);
	
	getch();
}