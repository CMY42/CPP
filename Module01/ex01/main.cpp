/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:54:51 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:16:12 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "ZombieName");

	for (int i = 0; i < N; ++i)
		horde[i].announce();

	delete[] horde;
	return 0;
}
