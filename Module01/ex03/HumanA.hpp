/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:27:34 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:27:35 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
