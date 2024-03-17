#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib> // pour atoi

int main(int argc, char* argv[])
{
	PmergeMe pm;

	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			int value = std::atoi(argv[i]);
			if (value < 0)
			{
				std::cerr << "Error: Only positive integers are allowed." << std::endl;
				return 1;
			}
			pm.addData(value);
		}
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << " <positive integers ...>" << std::endl;
		return 1;
	}

	pm.sortAndDisplay();

	return 0;
}
