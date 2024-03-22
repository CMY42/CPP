#include "Array.hpp"
#include <iostream>

int main()
{
	// Test avec un tableau d'entiers
	// int donc type simple
	Array<int> intArray(5);
	std::cout << "Testing int array:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = i * 5;
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl << "Size of int array: " << intArray.size() << std::endl;

	// Test avec un tableau de chaînes de caractères
	// chaine de caractere donc type plus complique
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	std::cout << "\nTesting string array:" << std::endl;
	for (unsigned int i = 0; i < stringArray.size(); ++i)
	{
		std::cout << stringArray[i] << " ";
	}
	std::cout << std::endl << "Size of string array: " << stringArray.size() << std::endl;

	// Test de copie et d'assignation
	std::cout << "\nTesting copy and assignment:" << std::endl;
	Array<int> copyArray = intArray; // Test de l'opérateur d'assignation
	Array<int> assignedArray(1);
	assignedArray = intArray; // Test de l'opérateur d'assignation

	// Modification de intArray pour montrer que copyArray reste inchangé
	intArray[0] = 100;
	std::cout << "Modified intArray[0] = " << intArray[0] << std::endl;
	std::cout << "copyArray[0] remains unchanged: " << copyArray[0] << std::endl;

	// Test d'accès hors limites
	try
	{
		std::cout << "\nAttempting to access an element out of bounds:" << std::endl;
		intArray[intArray.size()] = 10; // Ceci devrait lancer une exception
	}
	catch (const Array<int>::OutOfBoundsException& e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}

	return 0;
}
