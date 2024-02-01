#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // affiche le son du chat !!
	j->makeSound(); // affiche le son du chien !!
	meta->makeSound();

	delete i; // Doit afficher "Cat destructor called"
	delete j; // Doit afficher "Dog destructor called"
	delete meta; // Doit afficher "Animal destructor called"

	// WrongAnimal et WrongCat sont des classes qui ne sont pas liées à Animal
	// et Cat. Elles ne doivent pas avoir de destructeur virtuel.
	// Permets de voir la différence entre un destructeur virtuel et un
	// destructeur non virtuel.
	// Abscence de polymorphisme en raison de l'absence du mot clé virtual.
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongCat;
	delete wrongMeta;

	return 0;
}
