#include "iter.hpp"
#include <iostream>

// Cree un tableau d'entiers et un tableau de strings
int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 5, print);
	std::string tab2[] = {"salut", "les", "amis", "!"};
	iter(tab2, 4, print);
	return 0;
}
