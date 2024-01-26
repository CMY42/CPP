#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string name;
	Weapon& weapon; // Arme stockée par référence, ne peut pas être nullptr
	//Reference utile si on veut un lien permanent et immuable

public:
	HumanA(std::string name, Weapon& weapon);
	void attack() const;
};

#endif
