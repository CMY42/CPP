#ifndef PEMERGEME_HPP
#define PEMERGEME_HPP

#include <iostream> // pour std::cout
#include <vector> // container pour tableau dynamique
#include <algorithm> // pour std::sort et std::merge
#include <list> // container pour liste doublement chaînée
#include <ctime> // pour clock_t
#include <iterator> // pour std::distance

class PmergeMe
{
private:
	std::vector<int> dataVector; // container pour tableau dynamique
	std::list<int> dataList; // container pour liste doublement chaînée

public:
	PmergeMe();
	virtual ~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);

	void addData(int number);

	void sortAndDisplay();

	void displaySequence(const std::string& phase, const std::vector<int>& data) const;

	void displaySequence(const std::string& phase, const std::list<int>& data) const;

	void fordJohnsonSortList(std::list<int>& list);

	void insertionSortList(std::list<int>& data);

	std::list<int> mergeLists(std::list<int>& left, std::list<int>& right);

	void mergeSortList(std::list<int>& list, int threshold);

	void fordJohnsonSort(std::vector<int>& data);

	void insertionSort(std::vector<int>& data, int left, int right);

	void mergeSort(std::vector<int>& data, int left, int middle, int right);
};

#endif
