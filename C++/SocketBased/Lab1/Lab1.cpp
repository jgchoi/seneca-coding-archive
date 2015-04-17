#include <iostream>
#include <time.h>
#include "Object.h"
int main()
{
	int Max;
	std::cout << "How long should your buffer be? ";
	std::cin >> Max;
	Object obj(Max);
	srand(time(NULL));
	for (int x = 0; x < Max; x++)
	{
		int RandResult = rand() % 11;
		obj += RandResult;
	}
	obj.display();
	return 1;
}