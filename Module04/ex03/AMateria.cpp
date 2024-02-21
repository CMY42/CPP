#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	//std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	//std::cout << "AMateria " << this->_type << " constructor" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
	//std::cout << "AMateria copy constructor" << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &src)
{
	//std::cout << "AMateria assignation operator" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria " << this->_type << " use on " << target.getName() << std::endl;
}





