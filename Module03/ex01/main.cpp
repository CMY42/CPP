#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("Subzero");
	claptrap.attack("enemy");
	claptrap.takeDamage(8);
	claptrap.beRepaired(5);

	ScavTrap scavtrap("Scorpion");
	scavtrap.attack("Another Enemy");
	scavtrap.takeDamage(15);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();

	// Test de la copie et de l'affectation
	ScavTrap scavtrapCopy(scavtrap);
	ScavTrap scavtrapAssigned;
	scavtrapAssigned = scavtrap;

	scavtrapCopy.attack("Enemy Copy");
	scavtrapAssigned.attack("Enemy Assigned");

	return 0;
}
