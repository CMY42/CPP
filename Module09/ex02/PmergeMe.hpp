#ifndef PEMERGEME_HPP
#define PEMERGEME_HPP

#include <iostream> // pour std::cout
#include <vector> // container pour tableau dynamique
#include <algorithm> // pour std::sort
#include <list> // container pour liste doublement chaînée
#include <ctime> // pour clock_t

/*class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	virtual ~PmergeMe();

	void sortAndMeasure(const std::vector<int> &inputSequence);

private:
		void mergeSort(std::vector<int> &sequence);
		void sortList(std::list<int> &sequence);
		template <typename T>
		void displaySequence(const T &sequence) const;
		template <typename Container> //permet d'utiliser la fonction avec un vector ou une list, deux containers différents sans avoir à écrire deux fonctions différentes
		void measureSortingTime(Container &sequence);
};*/



// std::vector: Le tri est généralement plus rapide sur les vecteurs en raison de l'accès contigu à la mémoire, ce qui améliore la localité de cache et réduit le temps d'accès aux éléments lors du tri. L'algorithme de tri standard (std::sort) est très optimisé pour des structures de données comme le vecteur.
// std::list: Bien que std::list::sort() soit optimisé pour les listes chaînées, le processus de tri peut être plus lent que pour un vecteur car il n'y a pas d'accès direct aux éléments intermédiaires. Chaque déplacement à travers la liste nécessite de suivre les pointeurs depuis l'élément actuel jusqu'à l'élément cible, ce qui peut augmenter le temps d'exécution comparé à un vecteur.
// La différence de temps d'exécution sera donc principalement due à la manière dont la mémoire est accédée et manipulée dans chaque type de conteneur

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

	// Méthode pour afficher une séquence
	void displaySequence(const std::string& phase) const;
};

#endif
