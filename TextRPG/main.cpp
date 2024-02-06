#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "korean");
	bool OnOff = 1;

	PlayerChar pc = {};

	JobChoice(&pc);
	int choice = 0;
	while (true)
	{
		choice = ActChoice(&pc);

		switch (choice)
		{
		case HUNTING:
			RankChoice(&pc);
			break;
		case EXIT:
			SavePlayerData(&pc);
			return 0;
		}
	}
	return 0;
}