/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:53:00 by cmansey           #+#    #+#             */
/*   Updated: 2024/02/05 15:27:08 by cmansey          ###   ########.fr       */
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
	Fixed(); //constructeur par defaut,
	Fixed(const Fixed &copy); //constructeur par copie
	Fixed(const int intValue); //constructeur par parametre, convertit un int en nombre a virgule fixe (decalage de 8 bits a gauche)
	Fixed(const float floatValue); //constructeur par parametre, convertit un float en nombre a virgule fixe (x2^8 et en arrondissant)
	Fixed	&operator=(const Fixed &copy); //operateur d'affectation
	~Fixed(); //destructeur

	bool	operator>(const Fixed &copy) const; //operateur >, compare la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	bool	operator<(const Fixed &copy) const; //operateur <, compare la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	bool	operator>=(const Fixed &copy) const; //operateur >=, compare la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	bool	operator<=(const Fixed &copy) const; //operateur <=, compare la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	bool	operator==(const Fixed &copy) const; //operateur ==, compare la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	bool	operator!=(const Fixed &copy) const; //operateur !=, compare la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre

	Fixed	operator+(const Fixed &copy) const; //operateur +, additionne la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	Fixed	operator-(const Fixed &copy) const; //operateur -, soustrait la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	Fixed	operator*(const Fixed &copy) const; //operateur *, multiplie la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre
	Fixed	operator/(const Fixed &copy) const; //operateur /, divise la valeur du nombre a virgule fixe avec celle de l'objet passe en parametre

	Fixed	&operator++(); //operateur ++, incremente la valeur du nombre a virgule fixe, pre-incrementation
	Fixed	operator++(int); //operateur ++, incremente la valeur du nombre a virgule fixe, post-incrementation
	Fixed	&operator--(); //operateur --, decremente la valeur du nombre a virgule fixe, pre-decrementation
	Fixed	operator--(int); //operateur --, decremente la valeur du nombre a virgule fixe, post-decrementation

	static Fixed	&min(Fixed &a, Fixed &b); //renvoie la valeur la plus petite entre a et b
	static Fixed	&max(Fixed &a, Fixed &b); //renvoie la valeur la plus grande entre a et b
	static const Fixed	&min(const Fixed &a, const Fixed &b); //renvoie la valeur la plus petite entre a et b / Objets non modifiables (const &Fixed), modifie pas les objets passes et le resultat
	static const Fixed	&max(const Fixed &a, const Fixed &b); //renvoie la valeur la plus grande entre a et b

	int		getRawBits(void) const; //retourne la valeur du nombre a virgule fixe
	void	setRawBits(int const raw); //stocke la valeur du nombre a virgule fixe
	float	toFloat(void) const; //convertit le nombre a virgule fixe en float
	int		toInt(void) const; //convertit le nombre a virgule fixe en int (decalage de 8 bits a droite)
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); //surcharge de l'operateur << pour afficher un objet Fixed

#endif
