#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &copy); //constructeur de copie
	Animal &operator=(const Animal &copy);//opérateur d'affectation
	virtual ~Animal();// assure que le destructeur de la classe appropriée est appelé

	std::string getType() const;
	virtual void makeSound() const = 0; // "= 0" signifie que la fonction est purement virtuelle, ne peut pas être instanciée.
};

#endif
