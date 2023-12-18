#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phoneBook;

	int choice = 0;
	while (choice != 4) {
		std::cout << "\nMenu:\n";
		std::cout << "1. Add Contact\n";
		std::cout << "2. Display Contacts\n";
		std::cout << "3. Search Contact\n";
		std::cout << "4. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
			{
				std::string first, last, nick, phone, secret;
				std::cout << "Enter first name: ";
				std::cin >> first;
				std::cout << "Enter last name: ";
				std::cin >> last;
				std::cout << "Enter nickname: ";
				std::cin >> nick;
				std::cout << "Enter phone number: ";
				std::cin >> phone;
				std::cout << "Enter darkest secret: ";
				std::cin >> secret;
				phoneBook.addContact(first, last, nick, phone, secret);
				break;
			}
			case 2:
				phoneBook.displayContacts();
				break;
			case 3:
				phoneBook.searchContact();
				break;
			case 4:
				std::cout << "Exiting PhoneBook..." << std::endl;
				break;
			default:
				std::cout << "Invalid choice! Please enter again." << std::endl;
		}
	}
	return 0;
}
