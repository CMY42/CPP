#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("John", 2);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << "After increment: " << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << "After increment: " << bureaucrat << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("John", 2);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << "After increment: " << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << "After decrement: " << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << "After decrement: " << bureaucrat << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		// Exception car le grade est trop bas à l'initialisation
		Bureaucrat lowBureaucrat("Doe", 151);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception for low grade at init: " << e.what() << std::endl;
	}
	try
	{
		// Exception car le grade est trop haut à l'initialisation
		Bureaucrat lowBureaucrat("Doe", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception for high grade at init: " << e.what() << std::endl;
	}

	return 0;
}


/*int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("John", 150);
	std::cout << *bureaucrat << std::endl;
	try
	{
		bureaucrat->incrementGrade(); // on essaie d'augmenter le grade
	}
	catch (std::exception &e) //catch pour attraper l'exception
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *bureaucrat << std::endl;
	try
	{
		bureaucrat->decrementGrade(); // on essaie de diminuer le grade
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl; //catch pour attraper l'exception
	}
	std::cout << *bureaucrat << std::endl;
	delete bureaucrat;
	return 0;
}*/


