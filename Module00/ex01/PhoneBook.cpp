#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : numContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
	if (numContacts < MAX_CONTACTS)
	{
		contacts[numContacts].setContactInfo();
		numContacts++;
	}
	else
	{
		// Remplacer le contact le plus ancien
		std::cout << "PhoneBook is full. Replacing the oldest contact." << std::endl;
		for (int i = 0; i < MAX_CONTACTS - 1; ++i)
			contacts[i] = contacts[i + 1];

		contacts[MAX_CONTACTS - 1].setContactInfo();
	}
}

void PhoneBook::searchContacts() const
{
	if (numContacts == 0)
    {
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	std::cout << "| Index    | First Name | Last Name  | Nickname   |" << std::endl;
	std::cout << "|----------|------------|------------|------------|" << std::endl;

	for (int i = 0; i < numContacts; ++i)
		contacts[i].displayContactInfo(i);

	int index;
	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;

	if (std::cin.fail() || index < 0 || index >= numContacts)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Invalid index." << std::endl;
	}
	else
		contacts[index].displayFullContactInfo();
}


