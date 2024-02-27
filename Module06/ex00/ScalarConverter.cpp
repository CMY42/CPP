#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

//Conversion implicite est acceptee uniquement pour les promotions de type
//Dans le cas ou une conversion peut reduire la precision ou la plage de valeurs, une conversion explicite est necessaire et donc static_cast est utilise
void ScalarConverter::convert(const std::string &literal)
{
	double value = std::atof(literal.c_str());

	toChar(value);
	toInt(value);
	toFloat(value);
	toDouble(value);
}

//static_cast car permet de convertir explicitement d'un type a un autre a compile time
//c'est la maniere recommandee en C++ pour convertir des types
void ScalarConverter::toChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < static_cast<double>(CHAR_MIN) || value > static_cast<double>(CHAR_MAX))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<int>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::toInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::toFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "nanf" << std::endl; //nanf pour Not a Number ou infini
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

//pas besoin de static_cast car double est le type par defaut
//la value est deja de type double
void ScalarConverter::toDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "nan" << std::endl; //nan pour Not a Number ou infini
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
