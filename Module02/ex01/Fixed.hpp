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
	Fixed(const int intValue); //constructeur par parametre, convertit un int en nombre a virgule fixe (decalage de 8 bits a gauche)
	Fixed(const float floatValue); //constructeur par parametre, convertit un float en nombre a virgule fixe (x2^8 et en arrondissant)
	Fixed	&operator=(const Fixed &copy); //operateur d'affectation
	~Fixed(); //destructeur

	int		getRawBits(void) const; //retourne la valeur du nombre a virgule fixe
	void	setRawBits(int const raw); //stocke la valeur du nombre a virgule fixe
	float	toFloat(void) const; //convertit le nombre a virgule fixe en float
	int		toInt(void) const; //convertit le nombre a virgule fixe en int (decalage de 8 bits a droite)
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); //surcharge de l'operateur << pour afficher un objet Fixed

#endif
