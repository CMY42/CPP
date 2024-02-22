#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class Intern
{
private:
	AForm *createShrubberyCreationForm(const std::string &target) const; //en privé pour ne pas être utilisé en dehors de la classe
	AForm *createRobotomyRequestForm(const std::string &target) const; //permet de créer un formulaire de type RobotomyRequestForm
	AForm *createPresidentialPardonForm(const std::string &target) const;
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &copy);

	AForm *makeForm(const std::string &formName, const std::string &target) const; // prend un nom de formulaire et une cible, et renvoie un pointeur sur un nouvel objet de formulaire correspondant.
	class UnknownFormException : public std::exception //classe pour gérer les exceptions
	{
	public:
		virtual const char *what() const throw(); //permet de récupérer le message d'erreur
	};
};

#endif
