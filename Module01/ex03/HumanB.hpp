/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:27:40 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:27:40 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string name;
	Weapon* weapon; // Arme stockée par pointeur, peut être nullptr
	//Pointeur car plus flexible et pas obliger de passer une arme à la construction

public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon); // On peut assigner une arme à un HumanB
	void attack() const;
};

#endif
