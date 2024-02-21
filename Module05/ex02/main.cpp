#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int main()
{
	srand(time(NULL)); // On appele srand pour initialiser le générateur de nombre aléatoire
	// utile pour la fonction rand() dans la méthode execute de RobotomyRequestForm
	// va permettre de simuler une chance sur 2 de réussir l'opération
    try
	{
        Bureaucrat john("John Doe", 2);
        std::cout << john << std::endl;

        ShrubberyCreationForm form1("home");
        RobotomyRequestForm form2("Bender");
        PresidentialPardonForm form3("Ford Prefect");

        john.signForm(form1);
        john.signForm(form2);
        john.signForm(form3);

        john.executeForm(form1);
        john.executeForm(form2);
        john.executeForm(form3);
    }
	catch (std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat lowRank("Lowly Intern", 150);
        ShrubberyCreationForm form("garden");
        lowRank.signForm(form);
        lowRank.executeForm(form);
    }
	catch (std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


