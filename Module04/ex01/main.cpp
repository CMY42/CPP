#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Dog basic;
	{
		Dog tmp = basic;
	}

	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for ( int i = 0; i < 4; i++ )
		delete animals[i];

	return 0;
}
