#include "Entity.h"
#include "Player.h"

using namespace std;

Player::Player()
{
	_symbol = '@';
	_xp = 0;
	_lvl = 0;
}

//Getters
int Player::getLVL() { return _lvl; }

//Setters
void Player::setSymbol() { _symbol = '@'; }
void Player::setLVL(int lvl) { _lvl = lvl; }
