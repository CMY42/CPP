#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " operator= called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > amount)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " points of damage!" << std::endl;
		_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints + amount > 10)
	{
		std::cout << "ClapTrap " << _name << " is fully repaired!" << std::endl;
		_hitPoints = 10;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
		_hitPoints += amount;
	}
}


