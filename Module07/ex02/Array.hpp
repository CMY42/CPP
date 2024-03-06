#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
	public :
		//constructeur par defaut, initialise un tableau vide
		Array() : _array(nullptr), _size(0) {}

		//constructeur avec taille specifique, initialise un tableau de taille n
		//tous les elements sont initialises a la valeur par defaut de T
		Array(unsigned int n) : _array(new T[n]), _size(n) {}

		//constructeur par copie
		//assure une copie en profondeur du tableau garantissant que la modification d'un tableau ne modifie pas l'autre
		Array(Array const &src) : _array(nullptr), _size(0) { *this = src; }

		//destructeur liberant la memoire allouee
		~Array() { delete [] _array; }

		//operateur d'assignation permettant de copier un tableau dans un autre
		Array &operator=(const Array &rhs)
		{
			if (this != &rhs)
			{
				delete[] _array;
				_size = rhs._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		}

		//acces aux elements via l'operateur []
		//l'acces a un element inexistant declenche une exception
		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return _array[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size) throw std::exception();
				return _array[index];
		}

		//retourne la taille du tableau
		unsigned int size() const { return _size; }

	private :
		T *_array;
		unsigned int _size;
};

#endif
