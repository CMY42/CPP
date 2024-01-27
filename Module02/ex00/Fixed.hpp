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
