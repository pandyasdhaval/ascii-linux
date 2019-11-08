#pragma once
class Player
{
public:
	Player();

	//Getters
	char getSymbol();
	int getxPos();
	int getyPos();
	int getHealth();
	int getAttack();
	int getXP();
	int getLVL();

	//Setters
	void setxPos(int xPos);
	void setyPos(int yPos);
	void setHealth(int health);
	void setAttack(int attack);
	void setXP(int xp);
	void setLVL(int lvl);
private:
	char _symbol = '@';
	int _xPos;
	int _yPos;
	int _attack;
	int _health;
	int _xp = 0;
	int _lvl = 0;
};


