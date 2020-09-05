#include "Highscore.h"

Highscore::Highscore() :
	buttons{ },
	selector(0),
	x(180),
	y(17),
	score{ },
	highscore{ }
{
	buttons[0] = new Button(3, 39, 0x0F, "Enter/Space to Return to Menu");
	for (int row = 0; row < y; row++)
	{
		for (int col = 0; col < x; col++)
		{
			highscore[row][col] = ' ';
		}
	}
	for (int i = 0; i < 10; i++) {
		score[i] = 0;
	}
	c.X = 24;
	c.Y = 34;
}

Highscore::~Highscore()
{

}

void Highscore::loadscore()
{
	std::ifstream f;
	f.open("Score/highscore.csv");
	std::string data;
	int col = 0; //x
	int row = 0; //y
	while (getline(f, data))
	{
		for (int datarow = 0; datarow < (x * 2 - 1); datarow++) {
			if (data[datarow] == ',')
			{
				continue;
			}
			else
			{
				highscore[row][col] = data[datarow];
				col++;
			}

		}
		col = 0;
		row++;
	}
	f.close();

	std::ifstream file;
	file.open("score/Highscore.txt");
	std::string line;
	for (int i = 0; i < 10; i++)
	{
		string substr;
		getline(file, substr, ',');
		score[i] = std::stoi(substr);
	}
	file.close();
}

void Highscore::savescore(Player& player)
{
	std::ofstream file("score/Highscore.txt");
	int tempscore = player.getCoins();
	for (int i = 9; i > -1; i--) {
		if (tempscore < score[i]) {
			int tempscore2 = score[i];
			score[i] = tempscore;
			tempscore = tempscore2;
			//(tempscore ^= score[i]), (score[i] ^= tempscore), (tempscore ^= score[i]);
		}
	}
	string tempstr;
	for (int i = 0; i < 9; i++) {
		tempstr += (to_string(score[i]) + ",");
	}
	tempstr += to_string(score[9]);
	file << tempstr;
	file.close();
}

void Highscore::renderhighscore(Console& anotherC)
{
	for (int row = 0; row < y; row++)
	{
		for (int col = 0; col < x; col++)
		{
			if (highscore[row][col] == 'B')
			{
				anotherC.writeToBuffer(col, row + 2, "Û", 0x9B);
			}
			else if ((highscore[row][col] == 'Y'))
			{
				anotherC.writeToBuffer(col, row + 2, "Û", 0x7E);
			}
			else
			{
				anotherC.writeToBuffer(col, row + 2, " ", 0x7F);
			}
		}
	}
	buttons[0]->renderButton(anotherC, false);
	for (int i = 0; i < 9; i += 2) {
		anotherC.writeToBuffer(c, to_string(i) + ". " + to_string(score[i]), 0x0F);
		anotherC.writeToBuffer(c.X + 10, c.Y, to_string(i + 1) + ". " + to_string(score[i + 1]), 0x0F);
		c.Y += 2;
	}
}

int Highscore::getselector()
{
	return selector;
}

void Highscore::setselector(int select)
{
	selector = select;
}