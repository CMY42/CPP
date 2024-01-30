#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &copy); //constructeur de copie
	Cat &operator=(const Cat &copy);//opérateur d'affectation
	~Cat();

	void makeSound() const;
};

#endif
