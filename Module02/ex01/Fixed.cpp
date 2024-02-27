/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:52:45 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 15:11:27 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _value(copy._value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int intValue) //Constructeur qui prend un int, valeur devalee a gauche par _bits
{
	std::cout << "Int constructor called" << std::endl;
	_value = intValue << _bits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatValue * (1 << _bits));
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_value = copy._value; // permet d'eviter la copie de l'objet sur lui-meme
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const //convertit nombre a point fixe vers float
{
	return static_cast<float>(_value) / (1 << _bits); //static cast offre une meilleure  verification des types en C++
}

int Fixed::toInt(void) const //convertit nombre a point fixe vers int
{
	return _value >> _bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed) // surcharge de l'operateur << pour afficher un objet Fixed
{
	os << fixed.toFloat(); // on affiche la valeur du nombre a virgule fixe convertie en float
	return os;
}
