#include "Entity.h"
#include "Enemy.h"
using namespace std;


Enemy::Enemy()
{
}
string Enemy::getName() { return _name; }
/*char Enemy::getSymbol() { return _symbol; }
int Enemy::getxPos() { return _xPos; }
int Enemy::getyPos() { return _yPos; }
int Enemy::getHealth() { return _health; }
int Enemy::getAttack() { return _attack; }
int Enemy::getXP() { return _xp; }*/
int Enemy::getxDis() { return _xDis; }
int Enemy::getyDis() { return _yDis; }

void Enemy::setName(string name) { _name = name; }
/*void Enemy::setSymbol(char symbol) { _symbol = symbol; }
void Enemy::setxPos(int xPos) { _xPos = xPos; }
void Enemy::setyPos(int yPos) { _yPos = yPos; }
void Enemy::setHealth(int health) { _health = health; }
void Enemy::setAttack(int attack) { _attack = attack; }
void Enemy::setXP(int xp) { _xp = xp; }*/
void Enemy::setxDis(int xDis) { _xDis = xDis; }
void Enemy::setyDis(int yDis) { _yDis = yDis; }
