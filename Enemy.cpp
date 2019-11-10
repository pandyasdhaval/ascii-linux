#include "Entity.h"
#include "Enemy.h"
using namespace std;


Enemy::Enemy()
{
}
//Getters
string Enemy::getName() { return _name; }
int Enemy::getxDis() { return _xDis; }
int Enemy::getyDis() { return _yDis; }

//Setters
void Enemy::setName(string name) { _name = name; }
void Enemy::setxDis(int xDis) { _xDis = xDis; }
void Enemy::setyDis(int yDis) { _yDis = yDis; }
