#include "Player.h"



Player::Player()
{
}
char Player::getSymbol() { return _symbol; }
int Player::getxPos() { return _xPos; }
int Player::getyPos() { return _yPos; }
int Player::getHealth() { return _health; }
int Player::getAttack() { return _attack; }
int Player::getXP() { return _xp; }
int Player::getLVL() { return _lvl; }


void Player::setxPos(int xPos) { _xPos = xPos; }
void Player::setyPos(int yPos) { _yPos = yPos; }
void Player::setHealth(int health) { _health = health; }
void Player::setAttack(int attack) { _attack = attack; }
void Player::setXP(int xp) { _xp = xp; }
void Player::setLVL(int lvl) { _lvl = lvl; }
