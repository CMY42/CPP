#include "Zombie.hpp"
#include <iostream>

extern Zombie *zombieHorde(int N, std::string name);

int main()
{
	const int hordeSize = 5;
	Zombie *horde = zombieHorde(hordeSize, "Horde Zombie");

	for (int i = 0; i < hordeSize; ++i)
		horde[i].announce();

	delete[] horde;

	return 0;
}
