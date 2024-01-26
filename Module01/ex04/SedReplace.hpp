#ifndef SEDREPLACE_HPP
#define SEDREPLACE_HPP

#include <string>

class SedReplace
{
public:
	static std::string replaceString(const std::string& str, const std::string& from, const std::string& to);
};

#endif
