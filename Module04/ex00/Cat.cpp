#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	//cela permet d'appeler l'opérateur d'affectation de la classe de base
	//et garantit que TOUS les membres de la classe de base sont copiés correctement.
	//Ici pas necesaire car que TYPE mais pour plus tard
	Animal::operator=(copy);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}
