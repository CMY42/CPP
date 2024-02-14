#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(Cure const &src)
{
	//std::cout << "Cure copy constructor" << std::endl;
	*this = src;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor" << std::endl;
}

Cure &Cure::operator=(Cure const &src)
{
	//std::cout << "Cure assignation operator" << std::endl;
	AMateria::operator=(src); //Assure que tous les attributs de la classe mère sont copiés
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
