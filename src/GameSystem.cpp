#include "GameSystem.h"
using namespace std;


GameSystem::GameSystem()
{
	addFileName("environment/level1.txt");
	addFileName("environment/level2.txt");


	int row, col;

	getmaxyx(stdscr, row, col);
	_myWindow = _myGraphics.create_newwin(row - 2, col - 2, 1, 1);

	wrefresh(_myWindow);
}

bool GameSystem::playGame()
{
	bool win = false;
	bool death = false;
	bool playerExit = false;
	static int xpUpgrade = 50;
	static int i = 3;

	WINDOW *note;


	vector<string> noteString;

	while (!win && !death && !playerExit)
	{

		playerExit = _level.playerMove(_player, _enemy, _myWindow);//add win to the player move for xp

		if(playerExit) {
			_myGraphics.destroy_win(_myWindow);
			playerExit = true;

		} else {
			_level.enemyMove(_player, _enemy, death);

			if (_player.getXP() - xpUpgrade > 0)
			{

				_player.setLVL(_player.getLVL() + 1);

				note = _myGraphics.create_newwin_samecentre(20, 80, _myWindow);

				noteString.push_back("Congratulations! You levelled up!");
				noteString.push_back("Level: " + to_string(_player.getLVL()));
				noteString.push_back("XP: " +to_string( _player.getXP()));

				_myGraphics.printString_relativecentre(noteString, note);

				noteString.clear();
				wrefresh(note);

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

					wrefresh(note);
					getchar();
					werase(note);
					wrefresh(note);

					win = true;
					xpUpgrade = xpUpgrade * 2 *i;
					i++;
					_level.clearLvlData();

					werase(_myWindow);
					wrefresh(_myWindow);

					return win;
				}
				xpUpgrade = xpUpgrade * i;
				i++;
				_myGraphics.destroy_win(note);
			}

			_level.print(_player, _myWindow);
			wrefresh(_myWindow);

			if (death == true)
			{

				_level.print(_player, _myWindow);
				wrefresh(_myWindow);

				getchar();

                note = _myGraphics.create_newwin_samecentre(20, 80, _myWindow);
				noteString.push_back("RIP!");
				noteString.push_back("You Died Fighting!");

				_myGraphics.printString_relativecentre(noteString, note);

				noteString.clear();
;
				wrefresh(note);
				getchar();
				werase(note);
				wrefresh(note);
				_myGraphics.destroy_win(note);

				return false;
			}
		}
		
	}

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

