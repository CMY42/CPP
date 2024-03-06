#include "iter.hpp"
#include <iostream>

// Fonction template qui affiche le parametre passe en argument
template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

// Fonction main qui teste la fonction iter
// Elle cree un tableau d'entiers et un tableau de strings
int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 5, print);
	std::string tab2[] = {"salut", "les", "amis", "!"};
	iter(tab2, 4, print);
	return 0;
}
