#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer
{
public:
	Serializer(const Serializer &src) = delete; //delete car on ne veut pas de copie ni d'instance pour la classe Serializer
	Serializer & operator=(const Serializer &rhs) = delete;
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer() = delete;
	~Serializer() = delete;
};

#endif
