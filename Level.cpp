#include "Level.h"

using namespace std;

Level::Level()
{
}

void Level::load(string levelFileName, Player &player, vector<Enemy> &enemy)
{
	ifstream file;
	string buffer;

	file.open(levelFileName.c_str());
	if (file.fail())
	{
		perror(levelFileName.c_str());

		getchar();
		exit(1);
	}

	do {
		getline(file, buffer);
		_lvlData.push_back(buffer);
	} while (!file.eof());

	file.close();

	char tile;
	Enemy bufferEnemy;

	for (unsigned int i = 0; i < _lvlData.size(); i++)
	{
		for (unsigned int j = 0; j < _lvlData[i].size(); j++)
		{
			tile = _lvlData[i][j];
			switch (tile)
			{
			case '@':
				player.setxPos(i);
				player.setyPos(j);
				player.setHealth(100);
				player.setAttack(100);
				break;
			case 'S':
					bufferEnemy.setxPos(i);
					bufferEnemy.setyPos(j);
					bufferEnemy.setSymbol('S');
					bufferEnemy.setName("Snake");
					bufferEnemy.setHealth(10);
					bufferEnemy.setAttack(10);
					bufferEnemy.setXP(20);
					enemy.push_back(bufferEnemy);
					break;
			case 'G':
				bufferEnemy.setxPos(i);
				bufferEnemy.setyPos(j);
				bufferEnemy.setSymbol('G');
				bufferEnemy.setName("Goblin");
				bufferEnemy.setHealth(20);
				bufferEnemy.setAttack(20);
				bufferEnemy.setXP(40);
				enemy.push_back(bufferEnemy);
				break;
			case 'D':
				bufferEnemy.setxPos(i);
				bufferEnemy.setyPos(j);
				bufferEnemy.setSymbol('D');
				bufferEnemy.setName("Dragon");
				bufferEnemy.setHealth(10000);
				bufferEnemy.setAttack(10000);
				bufferEnemy.setXP(1000);
				enemy.push_back(bufferEnemy);
				break;
			case 'O':
				bufferEnemy.setxPos(i);
				bufferEnemy.setyPos(j);
				bufferEnemy.setSymbol('O');
				bufferEnemy.setName("Ogre");
				bufferEnemy.setHealth(100);
				bufferEnemy.setAttack(250);
				bufferEnemy.setXP(500);
				enemy.push_back(bufferEnemy);
				break;
			default:
				break;
			};
		}
	}
}

void Level::print(Player &player, WINDOW *aWindow)
{
	int row, col;
	unsigned int height, width = 0;

	height = _lvlData.size();

	getmaxyx(aWindow, row, col);

	for (unsigned int i = 0; i < _lvlData.size(); i++)
	{
		if(_lvlData[i].length() > width) {
			width = _lvlData[i].length();
		}
	}
	width++;

	mvwprintw(aWindow, ((row-height)/2) - 3, ((col-width)/2) + 0,"Player Level: %d", player.getLVL());
	mvwprintw(aWindow, ((row-height)/2) - 2 , ((col-width)/2) + 0,"Player XP: %d", player.getXP());

	for (unsigned int i = 0; i < _lvlData.size(); i++)
	{

		mvwaddstr(aWindow, ((row-height)/2) + i, ((col-width)/2) + 0, _lvlData[i].c_str());
	}

	wrefresh(aWindow);
}

bool Level::playerMove(Player &player, vector<Enemy> &enemy, WINDOW *aWindow)
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, player.getAttack());
	int i;
	int attack;
	char command;
	int isValid = 0;
	bool done = false;


	int y, x;
	getyx(aWindow, y, x);
	while (!isValid && !done)
	{
		mvwprintw(aWindow, y, x, "Move commands (w/s/a/d) ");

        halfdelay(5);
        command = getch();
        if(command != ERR) {
        	isValid = checkifValid(command, player);
        } else if(command == ERR) {
        	done = true;
        }
		
	}

	if(isValid == 3) {
		return true;
	} 
	else if (isValid == 1) {
		player.setXP(player.getXP() + 1);
		switch (command)
		{
		case 'w':
			_lvlData[player.getxPos()][player.getyPos()] = '.';
			player.setxPos(player.getxPos() - 1);
			_lvlData[player.getxPos()][player.getyPos()] = player.getSymbol();
			break;
		case 's':
			_lvlData[player.getxPos()][player.getyPos()] = '.';
			player.setxPos(player.getxPos() + 1);
			_lvlData[player.getxPos()][player.getyPos()] = player.getSymbol();
			break;
		case 'a':
			_lvlData[player.getxPos()][player.getyPos()] = '.';
			player.setyPos(player.getyPos() - 1);
			_lvlData[player.getxPos()][player.getyPos()] = player.getSymbol();
			break;
		case 'd':
			_lvlData[player.getxPos()][player.getyPos()] = '.';
			player.setyPos(player.getyPos() + 1);
			_lvlData[player.getxPos()][player.getyPos()] = player.getSymbol();
			break;
		default:
				break;
		};
	}
	else if(isValid == 2) {
		attack = attackRoll(randomEngine);
		switch (command)
		{
		case 'w':
			i = getEnemy(player.getxPos() - 1, player.getyPos(), enemy);
			if (enemy[i].getHealth() - attack > 0)
			{
				enemy[i].setHealth(enemy[i].getHealth() - attack);
			}
			else {
				player.setXP(player.getXP() + enemy[i].getXP());
				_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
				enemy[i] = enemy.back();
				enemy.pop_back();
			}
			break;
		case 's':
			i = getEnemy(player.getxPos() + 1, player.getyPos(), enemy);
			if (enemy[i].getHealth() - attack > 0)
			{
				enemy[i].setHealth(enemy[i].getHealth() - attack);
			}
			else {
				player.setXP(player.getXP() + enemy[i].getXP());
				_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
				enemy[i] = enemy.back();
				enemy.pop_back();
			}
			break;
		case 'a':
			i = getEnemy(player.getxPos(), player.getyPos() - 1, enemy);
			if (enemy[i].getHealth() - attack > 0)
			{
				enemy[i].setHealth(enemy[i].getHealth() - attack);
			}
			else {
				player.setXP(player.getXP() + enemy[i].getXP());
				_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
				enemy[i] = enemy.back();
				enemy.pop_back();
			}
			break;
		case 'd':
			i = getEnemy(player.getxPos(), player.getyPos() + 1, enemy);
			if (enemy[i].getHealth() - attack > 0)
			{
				enemy[i].setHealth(enemy[i].getHealth() - attack);
			}
			else {
				player.setXP(player.getXP() + enemy[i].getXP());
				_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
				enemy[i] = enemy.back();
				enemy.pop_back();
			}
			break;
		default:
			break;
		};
	}
	return false;	
}

int Level::checkifValid(char command, Player &player)
{
	char wTile = _lvlData[player.getxPos() - 1][player.getyPos()];
	char sTile = _lvlData[player.getxPos() + 1][player.getyPos()];
	char aTile = _lvlData[player.getxPos()][player.getyPos() - 1];
	char dTile = _lvlData[player.getxPos()][player.getyPos() + 1];
	switch (command)
	{
	case 'w':
		if (wTile == '.') {
			return 1;
		}
		else if (wTile != '#') {
			return 2;
		}
		else {
			return 0;
		}
		break;
	case 's':
		if (sTile == '.') {
			return 1;
		}
		else if (sTile != '#'){
			return 2;
		}
		else {
			return 0;
		}
		break;
	case 'a':
		if (aTile == '.') {
			return 1;
		}
		else if (aTile != '#') {
			return 2;
		}
		else {
			return 0;
		}
		break;
	case 'd':
		if (dTile == '.') {
			return 1;
		}
		else if (dTile != '#') {
			return 2;
		}
		else {
			return 0;
		}
		break;
	case 'q':
	case 'Q':
		return 3;
		break;
	default:
		return 0;
		break;
	}
}

bool Level::checkifValid(char command, Enemy &enemy)
{
	int xPos = enemy.getxPos();
	int yPos = enemy.getyPos();
	char wTile = _lvlData[xPos - 1][yPos];
	char sTile = _lvlData[xPos + 1][yPos];
	char aTile = _lvlData[xPos][yPos - 1];
	char dTile = _lvlData[xPos][yPos + 1];
	switch (command)
	{
	case 'w':
		if (wTile == '.') {
			return true;
		}
		else {
			return false;
		}
		break;
	case 's':
		if (sTile == '.') {
			return true;
		}
		else {
			return false;
		}
		break;
	case 'a':
		if (aTile == '.') {
			return true;
		}
		else {
			return false;
		}
		break;
	case 'd':
		if (dTile == '.') {
			return true;
		}
		else {
			return false;
		}
		break;
	default:
		return false;
		break;
	}
}
int Level::getEnemy(int xPos, int yPos, vector<Enemy> &enemy)
{
	for (unsigned int i = 0; i < enemy.size(); i++)
	{
		if (xPos == enemy[i].getxPos() && yPos == enemy[i].getyPos())
		{
			return i;
		}
	}
    return 0; //just place holder
}

void Level::enemyMove(Player &player, vector<Enemy> &enemy, bool &death)
{
	unsigned int i = 0; //check for impact 
	int canAttackValue;
	int attack;
	int nearPlayerValue;
	int randomMoveValue;

	static default_random_engine randomEngine(time(NULL));
	

	updateDistance(player, enemy);
	for (i = 0; i < enemy.size(); i++)
	{
		uniform_int_distribution<int> attackRoll(0, enemy[i].getAttack());
		uniform_int_distribution<int> randomMove(0, 4);
		canAttackValue = canAttack(enemy[i]);
		nearPlayerValue = nearPlayer(enemy[i]);
		

		if (canAttackValue > 0)
		{			
			attack = attackRoll(randomEngine);
			
			if (player.getHealth() - attack > 0)
			{
				player.setHealth(player.getHealth() - attack);
			}
			else {
				_lvlData[player.getxPos()][player.getyPos()] = 'X';

				death = true;
			}
		}
		else if (nearPlayerValue > 0) {

			switch (nearPlayerValue)
			{
			case 1:
				if (checkifValid('w', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setxPos(enemy[i].getxPos() - 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			case 2:
				if (checkifValid('s', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setxPos(enemy[i].getxPos() + 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			case 3:
				if (checkifValid('a', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setyPos(enemy[i].getyPos() - 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			case 4:
				if (checkifValid('d', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setyPos(enemy[i].getyPos() + 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			}
		}
		else
		{
			randomMoveValue = randomMove(randomEngine);
			switch (randomMoveValue)
			{
			case 0:
				break;
			case 1:
				if (checkifValid('w', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setxPos(enemy[i].getxPos() - 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			case 2:
				if (checkifValid('s', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setxPos(enemy[i].getxPos() + 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			case 3:
				if (checkifValid('a', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setyPos(enemy[i].getyPos() - 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			case 4:
				if (checkifValid('d', enemy[i]))
				{
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = '.';
					enemy[i].setyPos(enemy[i].getyPos() + 1);
					_lvlData[enemy[i].getxPos()][enemy[i].getyPos()] = enemy[i].getSymbol();
				}
				break;
			}
		}
	}
	
}

int  Level::canAttack(Enemy &enemy)
{
	//keep diagonals in mind

	if (enemy.getxDis() == -1 && enemy.getyDis() == 0)//w
	{
		return 1;
	}
	else if (enemy.getxDis() == 1 && enemy.getyDis() == 0)//s
	{
		return 2;
	}
	else if (enemy.getyDis() == -1 && enemy.getxDis() == 0)//a
	{
		return 3;
	}
	else if (enemy.getyDis() == 1 && enemy.getxDis() == 0)//d
	{
		return 4;
	}
	else//not the immediate next
	{
		return 0;
	}
}

int Level::nearPlayer(Enemy &enemy)
{
	int absX = abs(enemy.getxDis());
	int absY = abs(enemy.getyDis());

	int XDis = enemy.getxDis();
	int YDis = enemy.getyDis();
	if ((XDis >= -5 && XDis <= 5) && (YDis >= -5 && YDis <= 5))
	{
		if (absX > absY)
		{
			if (XDis < 0)
			{
				return 1;
			}
			else {
				return 2;
			}
		}
		else if (absY > absX)
		{
			if (YDis < 0)
			{
				return 3;
			}
			else {
				return 4;
			}
		}
		return 0;
	}
    return 0;//TODO change this so that enemy moves randomly and not just sit there idle
}


void Level::updateDistance(Player &player, vector<Enemy> &enemy)
{
	for (unsigned int i = 0; i < enemy.size(); i++)
	{
		enemy[i].setxDis(player.getxPos() - enemy[i].getxPos());
		enemy[i].setyDis(player.getyPos() - enemy[i].getyPos());
	}
}

void Level::clearLvlData()
{
	_lvlData.clear();
}
