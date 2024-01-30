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
	virtual void makeSound() const;// polymorphisme, permet de redéfinir la fonction dans les classes derivées
};

#endif
