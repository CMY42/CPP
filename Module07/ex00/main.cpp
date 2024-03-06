#include "whatever.hpp"
#include <string>

//Un template, est un outil puissant en C++ qui permet de générer des fonctions, des classes,
//ou même des méthodes au sein de classes qui peuvent opérer sur n'importe quel type.
//Les templates sont définis avec un ou plusieurs paramètres de type générique, ce qui permet leur instanciation avec des types concrets lors de l'utilisation.
int main(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	return 0;
}
