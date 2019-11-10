#ifndef _ENTITY_
#define _ENTITY_

class Entity {

public:
	Entity();

	//Getters
	char getSymbol();
	int getxPos();
	int getyPos();
	int getHealth();
	int getAttack();
	int getXP();

	//Setters
	virtual void setSymbol(char symbol);
	void setxPos(int xPos);
	void setyPos(int yPos);
	void setHealth(int health);
	void setAttack(int attack);
	void setXP(int xp);

protected:
	char _symbol;
	int _xPos;
	int _yPos;
	int _health;
	int _attack;
	int _xp;
};

#endif