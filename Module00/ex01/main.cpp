#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	do
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
		phoneBook.searchContacts();
	}
	while (command != "EXIT" && std::cin);

	return 0;
}
