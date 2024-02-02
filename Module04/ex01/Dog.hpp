#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;

public:
	Dog();
	Dog(const Dog &copy); //constructeur de copie
	Dog &operator=(const Dog &copy);//opérateur d'affectation
	~Dog();

	void makeSound() const;
};

#endif
