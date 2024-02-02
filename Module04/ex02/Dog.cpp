#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	_brain = new Brain(*copy._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}
