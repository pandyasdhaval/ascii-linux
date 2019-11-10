#pragma once
//#include "Entity.h"
//using namespace std;

class Player: public Entity {
public:
	Player();

	//Getters
	/*char getSymbol();
	int getxPos();
	int getyPos();
	int getHealth();
	int getAttack();
	int getXP();*/
	int getLVL();

	//Setters
	void setSymbol();
	/*void setxPos(int xPos);
	void setyPos(int yPos);
	void setHealth(int health);
	void setAttack(int attack);
	void setXP(int xp);*/
	void setLVL(int lvl);
protected:
	/*char _symbol = '@';
	int _xPos;
	int _yPos;
	int _attack;
	int _health;
	int _xp = 0;*/
	int _lvl = 0;
};


