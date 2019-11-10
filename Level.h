#pragma once
#include<iostream>
#include<vector>
#include<string>
//#include<conio.h>
#include<fstream>
#include<ctime>
#include<random>
#include<termios.h>
#include<stdio.h>
#include "Entity.h"
#include "Player.h"

#include "Enemy.h"
#include "Graphics.h"
using namespace std;

class Level
{
public:
	Level();
	void load(string levelFileName, Player &player, vector<Enemy> &enemy);
	void print(Player &player, WINDOW *aWindow);

	bool playerMove(Player &player, vector<Enemy> &enemy, WINDOW *aWindow);
	void enemyMove(Player &player, vector<Enemy> &enemy, bool &death);
	int checkifValid(char command, Player &player);
	bool checkifValid(char command, Enemy &enemy);
	int getEnemy(int xPos, int yPos, vector<Enemy> &enemy);

	int canAttack(Enemy &enemy);
	int nearPlayer(Enemy &enemy);
	void updateDistance(Player &player, vector<Enemy> &enemy);

	void clearLvlData();
private:
	vector<string> _lvlData;
};


