#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		// Création d'un bureaucrate avec un grade suffisamment élevé pour signer un formulaire.
		Bureaucrat bureaucrat("John", 4);
		std::cout << bureaucrat << std::endl;

		// Création d'un formulaire nécessitant un grade élevé pour la signature.
		Form form("Number 42", 3, 5);
		std::cout << form << std::endl;

		// Tentative de signature du formulaire par le bureaucrate.
		bureaucrat.signForm(form);

		// Augmentation du grade du bureaucrate et nouvelle tentative de signature.
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test avec des grades hors limites pour le bureaucrate et le formulaire.
	try
	{
		Bureaucrat highGradeBureaucrat("High Rank", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form invalidForm("Invalid Form", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}

