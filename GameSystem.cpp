#include "GameSystem.h"
using namespace std;


GameSystem::GameSystem()
{
	addFileName("level1.txt");
	addFileName("level2.txt");
	//setWindow();

	int row, col;
	//WINDOW *aWindow;
	getmaxyx(stdscr, row, col);
	//printf("\nstdscr is now %d, %d\n", row, col);
	_myWindow = _myGraphics.create_newwin(row - 2, col - 2, 1, 1);
	//setWindow(aWindow);
	wrefresh(_myWindow);
	//_level.load(getFileName(1).c_str(), _player, _enemy);
	//_level.print();
}

bool GameSystem::playGame()
{
	bool win = false;
	bool death = false;
	bool playerExit = false;
	static int xpUpgrade = 50;
	static int i = 3;

	WINDOW *note;
	//int row, col;

	vector<string> noteString;

	while (!win && !death && !playerExit)
	{
		//cout << "\n*********XP UPGRADE  = " << xpUpgrade << endl;TEST
		//cout << "\n**********i = " << i << endl;TEST
		playerExit = _level.playerMove(_player, _enemy, _myWindow);//add win to the player move for xp

		if(playerExit) {
			_myGraphics.destroy_win(_myWindow);
			playerExit = true;

		} else {
			_level.enemyMove(_player, _enemy, death);

			if (_player.getXP() - xpUpgrade > 0)
			{
				//getmaxyx(_myWindow, row, col);
				//note = _myGraphics.create_newwin(20, 80, row/2 - 10, col/2 - 40);
				_player.setLVL(_player.getLVL() + 1);

				note = _myGraphics.create_newwin_samecentre(20, 80, _myWindow);

				noteString.push_back("Congratulations! You levelled up!");
				noteString.push_back("Level: " + to_string(_player.getLVL()));
				noteString.push_back("XP: " +to_string( _player.getXP()));

				_myGraphics.printString_relativecentre(noteString, note);

				noteString.clear();
				//mvwprintw(note, 9, 0, "Congratulations! You levelled up!");
				//mvwprintw(note, 10, 0, "Level: %d", _player.getLVL());
				//mvwprintw(note, 11, 0, "XP: %d", _player.getXP());
				wrefresh(note);
				//cout << "\nCongratulations! You levelled up!\nLevel: " << _player.getLVL() << endl;
				//cout << "XP: " << _player.getXP() << endl;
				//system("Pause");
				
				//getch();
				getchar();
				werase(note);
				wrefresh(note);
				if (_player.getLVL() > 1)
				{
					note = _myGraphics.create_newwin_samecentre(20, 80, _myWindow);

					noteString.push_back("Congratulations! You won this level!");
					noteString.push_back("Level: " + to_string(_player.getLVL()));
					noteString.push_back("XP: " +  to_string(_player.getXP()));

					_myGraphics.printString_relativecentre(noteString, note);

					noteString.clear();
					//mvwprintw(note, 9, 0, "Congratulations! You won this level!");
					//mvwprintw(note, 10, 0, "Level: %d", _player.getLVL());
					//mvwprintw(note, 11, 0, "XP: %d", _player.getXP());
					wrefresh(note);
					getchar();
					werase(note);
					wrefresh(note);
					//cout << "\n\n\n\n\n\n\n\n\n\n\n";
					//cout <<"\nCongratulations! You won this level!\nLevel: " << _player.getLVL() << endl;
					//cout << "XP: " << _player.getXP() << endl;
					//_level.print(_player, getWindow());
					win = true;
					xpUpgrade = xpUpgrade * 2 *i;
					i++;
					_level.clearLvlData();

					werase(_myWindow);
					wrefresh(_myWindow);
					//system("Pause");
					return win;
				}
				xpUpgrade = xpUpgrade * i;
				i++;
				_myGraphics.destroy_win(note);
			}
			//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			_level.print(_player, _myWindow);
			wrefresh(_myWindow);

			if (death == true)
			{
				
				
				//wrefresh(note);
				//cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				_level.print(_player, _myWindow);
				wrefresh(_myWindow);

				//getmaxyx(_myWindow, row, col);
				//note = _myGraphics.create_newwin(20, 80, row/2 - 10, col/2 - 40);

				getchar();

				noteString.push_back("RIP!");
				noteString.push_back("You Died Fighting!");

				_myGraphics.printString_relativecentre(noteString, note);

				noteString.clear();

				//mvwprintw(note, 9, 0, "RIP!");
				//mvwprintw(note, 11, 0, "You Died Fighting!");
				wrefresh(note);
				getchar();
				werase(note);
				wrefresh(note);
				_myGraphics.destroy_win(note);
				//cout << "\nYou Died Fighting!\n";
				//system("Pause");
				return false;
			}
		}
		
	}
	//need a logic for the case of death and win
	//system("Pause");
	//getch();
	return false; //just place holder
}

void GameSystem::playerEnemyDist()
{
	for (unsigned int i = 0; i < _enemy.size(); i++)
	{
		_enemy[i].setxDis(_player.getxPos() - _enemy[i].getxPos());
		_enemy[i].setyDis(_player.getyPos() - _enemy[i].getyPos());		
	}
}
void GameSystem::addFileName(string fileName)
{
	_lvlFileName.push_back(fileName);
}
string GameSystem::getFileName(int lvl)
{
	return _lvlFileName[lvl - 1];
}

void GameSystem::lvlLoad(int lvl)
{
	_level.load(getFileName(lvl).c_str(), _player, _enemy);
	_level.print(_player, _myWindow);
}
int GameSystem::sizeNumFile()
{
	return _lvlFileName.size();
}

WINDOW * GameSystem::getWindow() {
	return _myWindow;
}

void GameSystem::setWindow(WINDOW *aWindow) {
	_myWindow = aWindow;
	
}

void GameSystem::delWindow() {
	_myGraphics.destroy_win(_myWindow);
}

