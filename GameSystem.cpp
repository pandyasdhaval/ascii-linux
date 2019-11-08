#include "GameSystem.h"



GameSystem::GameSystem()
{
	addFileName("level1.txt");
	addFileName("level2.txt");
	//_level.load(getFileName(1).c_str(), _player, _enemy);
	//_level.print();
}

bool GameSystem::playGame()
{
	bool win = false;
	bool death = false;
	static int xpUpgrade = 50;
	static int i = 3;
	while (!win && !death)
	{
		//cout << "\n*********XP UPGRADE  = " << xpUpgrade << endl;TEST
		//cout << "\n**********i = " << i << endl;TEST
		_level.playerMove(_player, _enemy);//add win to the player move for xp
		_level.enemyMove(_player, _enemy, death);
		if (_player.getXP() - xpUpgrade > 0)
		{
			_player.setLVL(_player.getLVL() + 1);
			cout << "\nCongratulations! You levelled up!\nLevel: " << _player.getLVL() << endl;
			cout << "XP: " << _player.getXP() << endl;
			system("Pause");
			if (_player.getLVL() > 1)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n";
				cout <<"\nCongratulations! You won this level!\nLevel: " << _player.getLVL() << endl;
				cout << "XP: " << _player.getXP() << endl;
				_level.print(_player);
				win = true;
				xpUpgrade = xpUpgrade * 2 *i;
				i++;
				_level.clearLvlData();
				system("Pause");
				return win;
			}
			xpUpgrade = xpUpgrade * i;
			i++;
		}
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		_level.print(_player);
	
		if (death == true)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			_level.print(_player);
			cout << "\nYou Died Fighting!\n";
			system("Pause");
			return false;
		}
	}
	//need a logic for the case of death and win
	system("Pause");
}

void GameSystem::playerEnemyDist()
{
	for (int i = 0; i < _enemy.size(); i++)
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
	_level.print(_player);
}
int GameSystem::sizeNumFile()
{
	return _lvlFileName.size();
}

