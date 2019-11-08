#include<iostream>
#include "GameSystem.h"
#include<fstream>
using namespace std;

void help(string fileName);

int main()
{
	bool win = true;
	int i = 0;
	GameSystem gameSystem;
	int choice;
	

	while (win) {
		cout << "1. Play Game\n2. Help!\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			while (win && i < gameSystem.sizeNumFile())
			{
				i++;
				gameSystem.lvlLoad(i);
				win = gameSystem.playGame();

			}

			if (win)
			{
				cout << "Congrats! You won the Game!!!\n";
				system("Pause");
				return 0;
			}

			break;
		case 2:
			help("Help.txt");
			break;
		default:
			cout << "Wrong Choice!!!";
			system("Pause");
			exit(99);
			break;
		}
	}
}
void help(string fileName)
{
	ifstream file;
	string buffer;

	file.open(fileName.c_str());
	if (file.fail())
	{
		perror(fileName.c_str());
		system("Pause");
		exit(1);
	}
	cout << "\n\n";
	do {
		getline(file, buffer);
		cout << buffer << endl;
	} while (!file.eof());
	cout << "\n\n";
	file.close();
}
