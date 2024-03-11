#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack> // pour std::stack
#include <deque> // pour std::deque

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {} // appel du constructeur de la classe mère (std::stack)
	MutantStack(MutantStack const &src) : std::stack<T>(src) {} // appel du constructeur de copie de la classe mère
	virtual ~MutantStack() {} // destructeur de la classe mère
	MutantStack &operator=(MutantStack const &rhs)// appel de l'opérateur d'affectation de la classe mère, fait partie de la definition de la classe template (MutantStack<T>) donc ok
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}

	// std::stack<T>::c est le conteneur utilisé par la classe std::stack
	// std::stack<T>::c.begin() retourne un itérateur sur le premier élément du conteneur
	// std::stack<T>::c.end() retourne un itérateur sur le dernier élément du conteneur
	// std::stack<T>::c.begin() et std::stack<T>::c.end() sont des méthodes de std::stack<T>::container_type
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }

	// const_iterator est un itérateur constant
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return std::stack<T>::c.begin(); }
	const_iterator end() const { return std::stack<T>::c.end(); }
};

#endif
