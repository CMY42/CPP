#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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

	// Implement and test WrongAnimal and WrongCat if necessary
	///////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!///////////////////////

	return 0;
}
