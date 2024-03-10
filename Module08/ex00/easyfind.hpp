#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <exception> // std::exception

// exception personnalisée pour signaler qu'un élément n'a pas été trouvé
class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Element not found";
	}
};

// fonction template pour trouver un élément dans un conteneur
// begin() et end() doivent être définis pour le conteneur, fonctionne avec tout conteneur STL qui supporte ces méthodes
// l'élément doit être comparable avec l'opérateur ==
// retourne l'index de l'élément dans le conteneur
// lance une exception NotFoundException si l'élément n'est pas trouvé
// find() retourne un itérateur sur l'élément trouvé, ou end() si l'élément n'est pas trouvé
// distance() retourne la distance entre deux itérateurs
template <typename T>
int easyFind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return std::distance(container.begin(), it);
}

#endif
