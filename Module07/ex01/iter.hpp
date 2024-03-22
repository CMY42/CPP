#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// T represente le type d'element du tableau
// array est le tableau
// length est la taille du tableau
// function est un pointeur sur une fonction qui prend un parametre de type T et ne retourne rien
template <typename T>
void iter(T *array, size_t length, void (*function)(T const &))
{
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

// Fonction template qui affiche le parametre passe en argument
template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

#endif
