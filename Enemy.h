#pragma once
#include<string>
using namespace std;

class Enemy: public Entity
{
public:
	Enemy();

	//Getters
	string getName();
	/*char getSymbol();
	int getxPos();
	int getyPos();
	int getHealth();
	int getAttack();
	int getXP();*/
	int getxDis();
	int getyDis();

	//setter
	void setName(string name);
	/*void setSymbol(char symbol);
	void setxPos(int xPos);
	void setyPos(int yPos);
	void setHealth(int health);
	void setAttack(int attack);
	void setXP(int xp);*/
	void setxDis(int xDis);
	void setyDis(int yDis);
protected:
	string _name;
	/*char _symbol;
	int _xPos;
	int _yPos;
	int _health;
	int _attack;
	int _xp;//xp to be given when dead;*/

	int _xDis;//dist from player
	int _yDis;//dist from player
};


