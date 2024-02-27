#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
public:
	static void convert(const std::string &literal);

//private car classe n'est pas destinee a etre instanciee
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();

	static void toChar(double value);
	static void toInt(double value);
	static void toFloat(double value);
	static void toDouble(double value);
};

#endif
