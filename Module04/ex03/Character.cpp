#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("default")
{
	//std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	//std::cout << "Character parameter constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	//std::cout << "Character copy constructor" << std::endl;
	*this = src;
}

Character::~Character()
{
	//std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

//La copie profonde est nécessaire pour s'assurer que chaque Character a ses propres copies uniques des objets AMateria dans son inventaire,
//plutôt que de partager des pointeurs vers les mêmes objets AMateria entre différents Character.
//Cela évite des problèmes tels que des modifications inattendues ou des suppressions multiples du même objet,
//ce qui pourrait mener à des comportements indéfinis ou à des erreurs d'exécution.
Character &Character::operator=(Character const &src)
{
	//std::cout << "Character assignation operator" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i]; //liberer la mememoire de l'ancien materia si elle existe
				_inventory[i] = NULL;
			}
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone(); // clonage seulement si la source n'est pas NULL
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = NULL; //On ne supprime pas la materia, on la déséquipe simplement
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
