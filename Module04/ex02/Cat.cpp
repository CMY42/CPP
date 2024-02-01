#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}
