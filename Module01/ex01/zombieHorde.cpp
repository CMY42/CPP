/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:55:02 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:20:52 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		std::stringstream ss; //on va creer a chaque iteration un nouvel objet ss
		ss << name << i;
		horde[i].setName(ss.str()); //convertit le contenu du flux ss en une chaine de caractere
	}
	return horde; //on retourne pointeur vers premiere element de la horde
}
