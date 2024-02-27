/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:27:42 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:27:43 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club"); //reference d'arme poitne toujours sur le meme objet "club"
	bob.attack();

	Weapon club2 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club2); // Pour HumanB on peut changer l'objet ou pointer vers un autre objet ou un nullptr
	jim.attack();
	club2.setType("some other type of club");
	jim.attack();
}
