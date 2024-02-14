#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	//std::cout << "MateriaSource copy constructor" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
	//std::cout << "MateriaSource assignation operator" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
		_materias[i] = src._materias[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return NULL;
}
