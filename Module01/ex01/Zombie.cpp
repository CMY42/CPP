/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:54:56 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:16:09 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName)
{
	name = newName;
}
