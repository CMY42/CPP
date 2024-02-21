#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception //gestion des exceptions pour les grades invalides
	{
	public:
		virtual const char *what() const throw(); //what pour retourner le message d'erreur
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw(); //throw() signifie que la fonction ne peut pas lancer d'exception
	};
	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat); //surcharge de l'opérateur << pour afficher les informations de l'objet

#endif
