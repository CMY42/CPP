/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:52:37 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 14:52:38 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_value; //stock la valeur du nombre a virgule fixe
	static const int	_bits = 8; //nombre de bits apres la virgule

public:
	Fixed(); //constructeur par defaut
	Fixed(const Fixed &copy); //constructeur par copie
	Fixed	&operator=(const Fixed &copy); //operateur d'affectation
	~Fixed(); //destructeur

	int		getRawBits(void) const; //retourne la valeur du nombre a virgule fixe
	void	setRawBits(int const raw); //stocke la valeur du nombre a virgule fixe
};

#endif
