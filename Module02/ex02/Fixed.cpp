/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:52:55 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 15:29:04 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _value(copy._value)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int intValue)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = intValue << _bits;
}

Fixed::Fixed(const float floatValue)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatValue * (1 << _bits));
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_value = copy._value; // permet d'eviter la copie de l'objet sur lui-meme
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//operateurs de comparaison

bool Fixed::operator>(const Fixed &copy) const
{
	return this->_value > copy._value;
}

bool Fixed::operator<(const Fixed &copy) const
{
	return this->_value < copy._value;
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return this->_value >= copy._value;
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return this->_value <= copy._value;
}

bool Fixed::operator==(const Fixed &copy) const
{
	return this->_value == copy._value;
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return this->_value != copy._value;
}

//operateurs arithmetiques

Fixed Fixed::operator+(const Fixed &copy) const
{
	return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	return Fixed(this->toFloat() / copy.toFloat());
}

//operateurs d'incrementation et de decrementation

Fixed& Fixed::operator++()
{
	this->_value++; //on incremente la valeur de l'objet courant
	return *this; //on retourne l'objet courant
}

Fixed Fixed::operator++(int) //postincrementation
{
	Fixed temp = *this; //on cree un objet temporaire qui va stocker la valeur de l'objet courant
	++(*this); //on incremente la valeur de l'objet courant
	return temp; //on retourne l'objet courant
}

Fixed& Fixed::operator--()
{
	this->_value--; //on decremente la valeur de l'objet courant
	return *this; //on retourne l'objet courant
}

Fixed Fixed::operator--(int) //postdecrementation
{
	Fixed temp = *this; //on cree un objet temporaire qui va stocker la valeur de l'objet courant
	--(*this); //on decremente la valeur de l'objet courant
	return temp; //on retourne l'objet courant
}

//Maximum and minimum

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _bits); //static cast offre une meilleure  verification des types en C++
}

int Fixed::toInt(void) const
{
	return _value >> _bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
