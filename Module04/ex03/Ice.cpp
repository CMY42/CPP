#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(Ice const &src)
{
	//std::cout << "Ice copy constructor" << std::endl;
	*this = src;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor" << std::endl;
}

Ice &Ice::operator=(Ice const &src)
{
	//std::cout << "Ice assignation operator" << std::endl;
	AMateria::operator=(src); //Assure que tous les attributs de la classe mère sont copiés
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
