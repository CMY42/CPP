#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : dataVector(other.dataVector), dataList(other.dataList) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		dataVector = other.dataVector;
		dataList = other.dataList;
	}
	return *this;
}

void PmergeMe::addData(int number)
{
	dataVector.push_back(number);
	dataList.push_back(number);
}

void PmergeMe::displaySequence(const std::string& phase) const
{
	std::cout << phase << ": ";
	if (phase == "Before")
	{
		for (int num : dataVector)
		{
			std::cout << num << " ";
		}
	}
	else if (phase == "After")
	{
		for (int num : dataList)
		{
			std::cout << num << " ";
		}
	}
	std::cout << std::endl;
}


void PmergeMe::sortAndDisplay()
{
	// Affichage avant le tri
	std::cout << "\033[31m" << "Before:" << "\033[0m" << " ";
	for (int num : dataVector)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	// Mesure du temps pour std::vector
	clock_t startVector = clock();
	std::sort(dataVector.begin(), dataVector.end());
	clock_t endVector = clock();

	// Affichage après le tri pour std::vector
	std::cout << "\033[34m" << "After (std::vector): " << "\033[0m";
	for (int num : dataVector)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "\033[34m" << "Time to process with std::vector: " << "\033[0m" << (double)(endVector - startVector) / CLOCKS_PER_SEC * 1000000 << " us\n";

	// Mesure du temps pour std::list
	clock_t startList = clock();
	dataList.sort();
	clock_t endList = clock();

	// Affichage après le tri pour std::list
	std::cout << "\033[33m" << "After (std::list): " << "\033[0m";
	for (int num : dataList)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
	std::cout << "\033[33m" << "Time to process with std::list: " << "\033[0m" << (double)(endList - startList) / CLOCKS_PER_SEC * 1000000 << " us\n";
}


