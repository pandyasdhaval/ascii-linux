#pragma once
#include<string>
#include "Level.h"
#include "Player.h"
using namespace std;
class GameSystem
{
public:
	GameSystem();
	bool playGame();
	void playerEnemyDist();

	void addFileName(string fileName);
	string getFileName(int lvl);
	void lvlLoad(int lvl);
	int sizeNumFile();

private:
	Level _level;
	Player _player;
	vector<Enemy> _enemy;
	vector<string> _lvlFileName;
};


