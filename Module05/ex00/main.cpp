#include "Bureaucrat.hpp"

int main()
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
}
