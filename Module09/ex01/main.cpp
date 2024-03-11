#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
		return 1;
	}

	RPN calculator; // permet de creer un objet de type RPN

	try
	{
		double result = calculator.evaluate(argv[1]); // permet d'evaluer l'expression et de stocker le resultat dans result
		std::cout << result << std::endl;
	}
	catch (const std::exception& e) // permet de capturer les exceptions
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
