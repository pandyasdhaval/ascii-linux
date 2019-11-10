#pragma once

class Player: public Entity {
public:
	Player();

	//Getters
	int getLVL();

	//Setters
	void setSymbol();

	void setLVL(int lvl);
protected:
	int _lvl = 0;
};


