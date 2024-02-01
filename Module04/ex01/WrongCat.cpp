#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	//cela permet d'appeler l'opérateur d'affectation de la classe de base
	//et garantit que TOUS les membres de la classe de base sont copiés correctement.
	//Ici pas necesaire car que TYPE mais pour plus tard
	WrongAnimal::operator=(copy);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat make a wrong sound" << std::endl;
}
