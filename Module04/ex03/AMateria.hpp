#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
	//unsigned int _xp;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual ~AMateria();
	AMateria &operator=(AMateria const &src);
	std::string const &getType() const; //retourne le type de la materia
	//unsigned int getXP() const;
	virtual AMateria* clone() const = 0; //retourne un pointeur sur une copie de la materia
	virtual void use(ICharacter &target); //effectue l’action de la materia
};

#endif
