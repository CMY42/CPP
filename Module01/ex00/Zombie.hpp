/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:52:59 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 13:52:59 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce(void) const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
