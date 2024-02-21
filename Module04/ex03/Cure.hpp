#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &src);
	virtual ~Cure();
	Cure &operator=(Cure const &src);
	virtual AMateria* clone() const; //retourne un pointeur sur une copie de la materia, classe abstraite
	virtual void use(ICharacter &target);
};

#endif
