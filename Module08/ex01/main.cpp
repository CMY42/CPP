#include "Span.hpp"

int main() {
	Span sp(10); // Crée un Span pouvant contenir jusqu'à 10 éléments.

	// Ajout de nombres un par un.
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// Affiche le plus court et le plus long span.
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	// Test de l'ajout de plusieurs nombres en utilisant une plage d'itérateurs.
	std::vector<int> moreNumbers = {1, 2, 13, 37, 42};
	sp.addNumber(moreNumbers.begin(), moreNumbers.end());

	// Affiche le plus court et le plus long span.
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	// Test de l'exception lorsque le Span est plein.
	try
	{
		sp.addNumber(100); // Ceci devrait déclencher une exception.
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Création d'un nouveau Span et test de l'exception pour les calculs de span.
	Span smallSpan(1);
	smallSpan.addNumber(5); // Ajout d'un seul nombre.

	try
	{
		std::cout << "Shortest Span Test, " << smallSpan.shortestSpan() << std::endl; // Ceci devrait déclencher une exception.
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Longest Span Test, " << smallSpan.longestSpan() << std::endl; // Ceci devrait déclencher une exception.
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}

