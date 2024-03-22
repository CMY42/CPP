#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	try
	{
		int index = easyFind(numbers, 3);
		std::cout << "Found at index: " << index << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		int index = easyFind(numbers, 6); // Cela va échouer
		std::cout << "Found at index: " << index << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
