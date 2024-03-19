#ifndef PEMERGEME_HPP
#define PEMERGEME_HPP

#include <iostream> // pour std::cout
#include <vector> // container pour tableau dynamique
#include <algorithm> // pour std::sort et std::merge
#include <list> // container pour liste doublement chaînée
#include <ctime> // pour clock_t
#include <iterator> // pour std::distance

// std::vector: Le tri est généralement plus rapide sur les vecteurs en raison de l'accès contigu à la mémoire,
// ce qui améliore la localité de cache et réduit le temps d'accès aux éléments lors du tri.
// L'algorithme de tri standard (std::sort) est très optimisé pour des structures de données comme le vecteur.
// std::list: Bien que std::list::sort() soit optimisé pour les listes chaînées,
// le processus de tri peut être plus lent que pour un vecteur car il n'y a pas d'accès direct aux éléments intermédiaires.
// Chaque déplacement à travers la liste nécessite de suivre les pointeurs depuis l'élément actuel jusqu'à l'élément cible,
// ce qui peut augmenter le temps d'exécution comparé à un vecteur.
// La différence de temps d'exécution sera donc principalement due à la manière dont la mémoire est accédée et manipulée dans chaque type de conteneur

// L'algorithme Ford-Johnson est une méthode de tri intéressante du point de vue de la théorie algorithmique,
// surtout pour son approche visant à réduire le nombre de comparaisons nécessaires.
// Cependant, sa complexité et ses performances variables en fonction du contexte d'utilisation limitent son application pratique
// par rapport à d'autres algorithmes de tri plus courants et plus facilement implémentables
// Diviser pour régner : L'algorithme divise la liste à trier en petits groupes.
// Idéalement, ces groupes sont de taille 2 (mais cela peut varier selon l'implémentation et la taille de la liste).
// Trouver les médianes : Pour chaque groupe, trouvez la médiane en les comparant.
// Pour un groupe de deux, c'est simplement en comparant quel élément est plus grand. Les médianes servent de points de référence pour les étapes suivantes.
// Diviser selon la médiane des médianes : Une fois que vous avez une liste de médianes pour chaque groupe,
// trouvez la médiane de ces médianes. Cette médiane des médianes est utilisée pour diviser la liste originale en deux parties :
// une partie avec des éléments inférieurs à la médiane des médianes et l'autre avec des éléments supérieurs.
// Tri récursif : Appliquez récursivement l'algorithme aux deux moitiés de la liste,
// en utilisant la même méthode pour diviser chaque moitié en groupes, trouver les médianes, et ainsi de suite.
// Fusion et insertion : Une fois que vous avez atteint des listes de taille gérable
// (souvent quand elles sont réduites à un ou deux éléments), vous les fusionnez en utilisant une méthode d'insertion,
// en plaçant chaque élément à sa position correcte par rapport aux autres dans la liste finale triée.

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

	// Méthode pour ajouter des éléments dans les conteneurs
	void addData(int number);

	// Méthode pour trier et afficher les séquences
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

	void simpleSort(std::list<int>& data);
};

#endif
