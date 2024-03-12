#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	std::string info;
	Data(const std::string& info) : info(info) {}
};

#endif
