#pragma once
#include<string>
using namespace std;

class Enemy: public Entity
{
public:
	Enemy();

	//Getters
	string getName();
	int getxDis();
	int getyDis();

	//setter
	void setName(string name);
	void setxDis(int xDis);
	void setyDis(int yDis);
protected:
	string _name;
	int _xDis;//dist from player
	int _yDis;//dist from player
};


