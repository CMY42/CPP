#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream> // pour std::cout
#include <vector> // pour std::vector
#include <algorithm> // pour std::min et std::max
#include <exception> // pour std::exception
#include <iterator> // pour std::distance


class Span
{
public:
	Span(unsigned int N); // constructeur specifique, N est le nombre max d'entiers
	Span(Span const &other); // constructeur par copie
	Span &operator=(Span const &other); // operateur d'affectation
	~Span(); // destructeur

	void addNumber(int number); // Pour ajouter un seul nombre.
	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end); // Pour ajouter plusieurs nombres.
	int shortestSpan(); // retourne la difference entre les deux nombres les plus proches
	int longestSpan(); // retourne la difference entre le plus grand et le plus petit nombre

	// Classe d'exception pour gestion d'erreurs
	// Elles sont derivees de std::exception et ne sont donc pas des fonctions membres
	class FullSpanException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

private:
	Span(); // constructeur par defaut
	unsigned int _n; // nombre max d'entiers
	std::vector<int> _numbers; // liste des entiers
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
	typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
	difference_type distance = std::distance(begin, end);
	if (_numbers.size() + distance > _n)
		throw FullSpanException();

	_numbers.insert(_numbers.end(), begin, end);
}

#endif
