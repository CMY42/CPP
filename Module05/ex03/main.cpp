#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	AForm* form;

	try
	{
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		delete form; //permet de supprimer le formulaire
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		form = someRandomIntern.makeForm("presidential pardon", "Zaphod Beeblebrox");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		form = someRandomIntern.makeForm("shrubbery creation", "Marvin");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		form = someRandomIntern.makeForm("unknown form", "Target");
	}
	catch (Intern::UnknownFormException &e) //permet de capturer l'exception UnknownFormException, utile pour traiter specifiauement les erreurs liees a la recherche de formulaire
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}


