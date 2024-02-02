#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &copy); //constructeur de copie
	Cat &operator=(const Cat &copy);//opérateur d'affectation
	~Cat();

	void makeSound() const;
};

#endif
