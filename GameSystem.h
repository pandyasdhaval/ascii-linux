#pragma once
#include<string>
#include<vector>
#include "Level.h"
#include "Entity.h"
#include "Player.h"

#include "Graphics.h"

class GameSystem
{
public:
	GameSystem();

	bool playGame();
	void lvlLoad(int lvl);

	int sizeNumFile();
	void playerEnemyDist();

	
	Graphics getGraphics();//TODO remove?
	
	void delWindow();

	//Setters
	void setWindow(WINDOW *aWindow);
	void addFileName(string fileName);

	//Getters
	WINDOW *getWindow();
	string getFileName(int lvl);

private:
	Level _level;
	Player _player;
	vector<Enemy> _enemy;
	vector<string> _lvlFileName;
	Graphics _myGraphics;
	WINDOW *_myWindow;
};


