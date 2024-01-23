#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << "Address of the string variable: " << &str << std::endl;
	std::cout << "Address held by stringPTR: " << ptr << std::endl;
	std::cout << "Address held by stringREF: " << &ref << std::endl;

	// Affichage des valeurs
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *ptr << std::endl;
	std::cout << "Value pointed to by stringREF: " << ref << std::endl;

	return (0);
}
