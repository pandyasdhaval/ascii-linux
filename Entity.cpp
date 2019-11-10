#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

//class Player;

Entity::Entity() {

}

char Entity::getSymbol() { return _symbol; }
int Entity::getxPos() { return _xPos; }
int Entity::getyPos() { return _yPos; }
int Entity::getHealth() { return _health; }
int Entity::getAttack() { return _attack; }
int Entity::getXP() { return _xp; }


void Entity::setSymbol(char symbol) { _symbol = symbol; }
void Entity::setxPos(int xPos) { _xPos = xPos; }
void Entity::setyPos(int yPos) { _yPos = yPos; }
void Entity::setHealth(int health) { _health = health; }
void Entity::setAttack(int attack) { _attack = attack; }
void Entity::setXP(int xp) { _xp = xp; }