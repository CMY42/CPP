#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	//cela permet d'appeler l'opérateur d'affectation de la classe de base
	//et garantit que TOUS les membres de la classe de base sont copiés correctement.
	//Ici pas necesaire car que TYPE mais pour plus tard
	Animal::operator=(copy);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}
