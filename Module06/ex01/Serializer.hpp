#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer
{
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer(); // dans private car non definie
	Serializer(const Serializer &src);
	Serializer & operator=(const Serializer &rhs);
	~Serializer();
};

#endif
