/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:54:59 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:20:54 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <sstream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void) const;
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
