#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "Animal make a sound" << std::endl;
}
