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

void PmergeMe::displaySequence(const std::string& phase, const std::vector<int>& data) const
{
	for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displaySequence(const std::string& phase, const std::list<int>& data) const
{
	for (std::list<int>::const_iterator it = data.begin(); it != data.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::insertionSortList(std::list<int>& list)
{
	if (list.size() <= 1) return; // Aucun tri nécessaire pour une liste de 0 ou 1 élément.

	std::list<int>::iterator it1 = list.begin();
	++it1; // Commencez à partir du deuxième élément

	while (it1 != list.end()) {
		int val = *it1; // Sauvegardez la valeur actuelle à insérer
		std::list<int>::iterator it2 = it1;
		std::list<int>::iterator place;

		// Trouvez l'emplacement d'insertion approprié pour la valeur actuelle
		bool found = false;
		for (place = list.begin(); place != it1; ++place) {
			if (*place > val)
			{
				found = true;
				break;
			}
		}

		if (found)
		{
			// Si un emplacement d'insertion est trouvé avant it1, insérez la valeur et effacez l'ancien élément
			list.insert(place, val); // Insère la valeur avant 'place'
			it1 = list.erase(it1); // Efface l'élément à 'it1', retourne l'itérateur au suivant
		}
		else
		{
			++it1; // Continuez à l'élément suivant si aucun emplacement n'est trouvé
		}
	}
}

std::list<int> PmergeMe::mergeLists(std::list<int>& left, std::list<int>& right)
{
	std::list<int> result;
	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}

	// Ajoutez les éléments restants
	while (!left.empty())
	{
		result.push_back(left.front());
		left.pop_front();
	}

	while (!right.empty())
	{
		result.push_back(right.front());
		right.pop_front();
	}

	return result;
}

void PmergeMe::mergeSortList(std::list<int>& list, int threshold)
{
	if (list.size() <= 1) return;

	// Divisez la liste en deux moitiés
	std::list<int> left;
	std::list<int> right;
	std::list<int>::iterator middle = list.begin();
	std::advance(middle, list.size() / 2);

	left.splice(left.begin(), list, list.begin(), middle);
	right.splice(right.begin(), list, middle, list.end());

	// Tri fusion récursif sur les moitiés
	if (left.size() > threshold) mergeSortList(left, threshold);
	else insertionSortList(left);
	if (right.size() > threshold) mergeSortList(right, threshold);
	else insertionSortList(right);

	// Fusionner les moitiés triées
	list = mergeLists(left, right);
}

void PmergeMe::fordJohnsonSortList(std::list<int>& list)
{
	int threshold = 16; // Seuil pour passer du tri fusion au tri par insertion, ajustez selon les besoins
	mergeSortList(list, threshold);
}

void PmergeMe::insertionSort(std::vector<int>& data, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = data[i];
		int j = i - 1;
		while (j >= left && data[j] > key)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = key;
	}
}

void PmergeMe::mergeSort(std::vector<int>& data, int left, int right, int threshold)
{
	if (left < right)
	{
		if (right - left <= threshold)
		{ // Utilisez le tri par insertion pour de petites sous-listes
			insertionSort(data, left, right);
		}
		else
		{
			int mid = left + (right - left) / 2;
			mergeSort(data, left, mid, threshold);
			mergeSort(data, mid + 1, right, threshold);
			std::inplace_merge(data.begin() + left, data.begin() + mid + 1, data.begin() + right + 1);
		}
	}
}

void PmergeMe::fordJohnsonSort(std::vector<int>& data)
{
	int threshold = 16; // Seuil pour passer du tri fusion au tri par insertion, ajustez selon les besoins
	mergeSort(data, 0, data.size() - 1, threshold);
}

void PmergeMe::simpleSort(std::list<int>& data)
{
	data.sort(); // Utilisation de la méthode sort de std::list
}


void PmergeMe::sortAndDisplay()
{
	// Affichage avant le tri
	std::cout << "\033[31mBefore:\033[0m ";
	displaySequence("Before", dataVector);

	// Mesure du temps pour std::vector avec Ford-Johnson
	clock_t startVector = clock();
	fordJohnsonSort(dataVector); //tri du std::vector
	clock_t endVector = clock();

	// Affichage après le tri pour std::vector
	std::cout << "\033[34mAfter (std::vector):\033[0m ";
	displaySequence("After", dataVector);
	std::cout << "\033[34mTime to process with std::vector:\033[0m " << (double)(endVector - startVector) / CLOCKS_PER_SEC * 1000000 << " us\n";

	// Mesure du temps pour std::list avec Ford-Johnson
	clock_t startList = clock();
	fordJohnsonSortList(dataList); // Tri du std::list
	clock_t endList = clock();

	std::cout << "\033[33mAfter (std::list):\033[0m ";
	displaySequence("After", dataList);
	std::cout << "\033[33mTime to process with std::list:\033[0m " << (double)(endList - startList) / CLOCKS_PER_SEC * 1000000 << " us\n";
}



