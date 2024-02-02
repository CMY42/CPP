#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal &copy); //constructeur de copie
	Animal &operator=(const Animal &copy);//opérateur d'affectation
	virtual ~Animal();// assure que le destructeur de la classe appropriée est appelé

	std::string getType() const;
	virtual void makeSound() const = 0; // "= 0" signifie que la fonction est purement virtuelle, ne peut pas être instanciée.
};

#endif

//Classe abstraite : classe qui contient au moins une fonction virtuelle pure.
//Une fonction virtuelle pure est une fonction qui n'a pas d'implémentation dans la classe de base.
//Une classe abstraite ne peut pas être instanciée.
//Peut etre utilisee comme classe de base pour d'autres classes.

//Une methode virtuelle pure est une methode qui n'a pas d'implementation dans la classe de base.
//Une classe qui contient au moins une methode virtuelle pure est une classe abstraite.
//Ne possede pas de corps. Toutes les classes qui heritent de cette classe doivent implementer cette methode.
//Les methodes purement virtuelles sont souvent utilisees pour definir une interface que les classes derivees doivent implementer.
