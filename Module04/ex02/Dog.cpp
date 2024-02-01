#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}
