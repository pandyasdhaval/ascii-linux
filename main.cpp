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
	//initscr(); /*start curses mode*/
	//raw(); /*line buffering disabled*/
	//keypad(stdscr, TRUE); // we get F1, F2 etc...
	//noecho(); //don't echo while we do getch
	myGraphics.init();

	GameSystem gameSystem;

	getmaxyx(stdscr, row, col); // get the number of rows and columns

	printw("This screen has %d rows and %d columns\n", row, col);
	refresh();


	vector<string> messages;

	while (win && !exit) {

		//getmaxyx(stdscr, row, col);
		//myWindow = myGraphics.create_newwin(20, 20, row/2 - 10, col/2-10);
		myWindow = myGraphics.create_newwin_samecentre(20, 20, stdscr);
		//wrefresh(myWindow);
		

		str = "1. Play Game";
		messages.push_back(str);

		//getmaxyx(myWindow, row, col);
		//mvwprintw(myWindow, row/2 - 1, (col - str.length())/2, "%s", str.c_str());
		
		//wrefresh(myWindow);
		str = "2. Help!";
		messages.push_back(str);

		myGraphics.printString_relativecentre(messages, myWindow);
		messages.clear();
		//mvwprintw(myWindow, row/2, (col - str.length())/2, "%s", str.c_str());
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
				myWindow = myGraphics.create_newwin_samecentre(20, 80, stdscr);
				//wrefresh(myWindow);
		

				str = "Congrats! You won the Game!!!";
				messages.push_back(str);
				myGraphics.printString_relativecentre(messages, myWindow);
				wrefresh(myWindow);

				str.clear();
				//cout << "Congrats! You won the Game!!!\n";
				//system("Pause");
				getchar();
				myGraphics.destroy_win(myWindow);
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
	// int row;
	// int col;

	//int i = 1;
	//int j = 1;

	Graphics someGraphics;
	WINDOW *someWindow;

	file.open(fileName.c_str());
	if (file.fail())
	{
		perror(fileName.c_str());
		//system("Pause");
		getchar();
		exit(1);
	}
	
	//cout << "\n\n";
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
	
	// file.clear();
	// file.seekg(0, ios::beg);

	// getmaxyx(stdscr, row, col);

	// someWindow = someGraphics.create_newwin(length, max, (row - length)/2, (col - max)/2);
	someWindow = someGraphics.create_newwin_samecentre(length, max, stdscr);
	//wrefresh(someWindow);
	someGraphics.printString_relativecentre(myStr, someWindow);

	// while(!file.eof()) {
	// 	getline(file, buffer);
	// 	mvwprintw(someWindow, i, j, "%s",buffer.c_str());
	// 	i++;
	// 	//waddstr(someWindow, buffer.c_str());
	// 	//waddstr(someWindow, "\n");
	// 	wrefresh(someWindow);
	// }
	getmaxyx(someWindow, length, max);
	mvwprintw(someWindow, length - 2, 1, "Any key: ");
	wrefresh(someWindow);
	getch();
	//werase(someWindow);
	//wrefresh(someWindow);

	
	someGraphics.destroy_win(someWindow);
	refresh();
	//cout << "\n\n";
	file.close();
}

/*void default_msg(WINDOW *someWindow) {
	int row, col;
	Graphics someGraphics;
	//WINDOW *someWindow;

	getmaxyx(someWindow, row, col);

	//someWindow = someGraphics.create_newwin(20, 20, (row - 20)/2, (col - 20)/2);
	mvwprintw(someWindow, row - 2, 1, "Wrong Choice!!!");
	mvwprintw(someWindow, row - 1, 1, "Choose Again? ");
	wrefresh(someWindow);
	
	getch();
}*/