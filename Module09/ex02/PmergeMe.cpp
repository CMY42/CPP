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

// Méthode pour ajouter des éléments dans les conteneurs
void PmergeMe::addData(int number)
{
	dataVector.push_back(number);
	dataList.push_back(number);
}

// Affiche les éléments de la séquence
// STD::VECTOR
void PmergeMe::displaySequence(const std::string& phase, const std::vector<int>& data) const
{
	for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Affiche les éléments de la séquence
// STD::LIST
void PmergeMe::displaySequence(const std::string& phase, const std::list<int>& data) const
{
	for (std::list<int>::const_iterator it = data.begin(); it != data.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Tri par insertion pour une liste doublement chaînée
// STD::LIST
void PmergeMe::insertionSortList(std::list<int>& list)
{
	if (list.size() <= 1) return; // Aucun tri nécessaire pour une liste de 0 ou 1 élément.

	std::list<int>::iterator it1 = list.begin();
	++it1; // Commencez à partir du deuxième élément

	while (it1 != list.end())
	{
		int val = *it1; // Sauvegardez la valeur actuelle à insérer
		std::list<int>::iterator it2 = it1;
		std::list<int>::iterator place;

		// Trouvez l'emplacement d'insertion approprié pour la valeur actuelle
		bool found = false;
		for (place = list.begin(); place != it1; ++place)
		{
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

// Fonction pour fusionner deux listes triées en une seule liste triée
// STD::LIST
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

// Tri fusion pour une liste doublement chaînée
// STD::LIST
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

// Tri fusion pour un tableau dynamique
// STD::LIST
void PmergeMe::fordJohnsonSortList(std::list<int>& list)
{
	int threshold = 16; // Seuil pour passer du tri fusion au tri par insertion, ajustez selon les besoins
	mergeSortList(list, threshold);
}

// Tri par insertion pour un tableau dynamique
// STD::VECTOR
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

// Tri fusion pour un tableau dynamique
// STD::VECTOR
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

// Tri Ford-Johnson pour un tableau dynamique
// STD::VECTOR
void PmergeMe::fordJohnsonSort(std::vector<int>& data)
{
	int threshold = 16; // Seuil pour passer du tri fusion au tri par insertion, ajustez selon les besoins
	mergeSort(data, 0, data.size() - 1, threshold);
}

// Affiche les séquences avant et après le tri, et mesure le temps d'exécution pour chaque type de conteneur
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

//Diffenrence entre std::vector et std::list
//surout en matière de gestion de la mémoire et d'opérations sur les éléments.

//std::list est une liste doublement chaînée,
//ce qui signifie que chaque élément est lié à ses voisins avant et arrière.
//Cela permet des insertions et des suppressions rapides à n'importe quelle position dans la liste,
//mais cela signifie également que l'accès aux éléments par indexation est plus lent que pour std::vector.

//std::vector est un tableau dynamique, ce qui signifie que les éléments sont stockés dans un bloc de mémoire contigu.
//ce qui offre une excellente localité de référence et un accès rapide aux éléments par indexation.
//Cela le rend idéal pour des opérations qui bénéficient de l'accès aléatoire ou lorsque la taille du conteneur
//est relativement stable et que peu d'insertions ou de suppressions sont effectuées à des positions autres que la fin du conteneur.

//la difference de temps d'execution entre std::vector et std::list est que std::vector est plus rapide que std::list.
//Cela est dû à la localité de référence et à l'accès rapide aux éléments par indexation offerts par std::vector,
//ce qui le rend plus efficace pour les opérations de tri et d'accès aléatoire.
//std::list, étant une liste chaînée, souffre d'un temps d'accès plus lent aux éléments, ce qui peut ralentir certaines étapes du processus de tri,
//particulièrement dans les cas où un accès direct et répété aux éléments est nécessaire.
//Cependant, std::list peut présenter des avantages pour les insertions et suppressions d'éléments pendant le tri,
//grâce à sa capacité à insérer ou supprimer des éléments rapidement sans nécessiter de réallocations

//Ford-Johnson est un algorithme de tri qui utilise une approche de diviser pour régner pour trier une liste d'éléments.
//Il divise la liste en petits groupes, trouve les médianes pour chaque groupe, puis les fusionne en utilisant un tri fusion.
//Il utilise également un tri par insertion pour de petites sous-listes, ce qui améliore les performances dans certains cas.
//Cependant, il a une complexité et des performances variables en fonction du contexte d'utilisation. Notamment pour les listes de taille variable.

