#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	_brain = new Brain(*copy._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}
