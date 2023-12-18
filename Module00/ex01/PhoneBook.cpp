#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	contactCount = 0;
}
void PhoneBook::addContact(const std::string& first, const std::string& last, const std::string& nick,
					const std::string& phone, const std::string& secret)
{
	if (contactCount < 8)
	{
		contacts[contactCount].setContact(first, last, nick, phone, secret);
		++contactCount;
		std::cout << "Contact added successfully!" << std::endl;
	}
	else
		std::cout << "PhoneBook is full. Cannot add more contacts!" << std::endl;
}

void PhoneBook::displayContacts() const
{
	std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
	for (int i = 0; i < contactCount; ++i)
		contacts[i].displayShortInfo(i);
}

void PhoneBook::displayContactDetails(int index) const
{
	if (index >= 0 && index < contactCount)
		contacts[index].displayFullInfo();
	else
		std::cout << "Invalid index. Contact not found!" << std::endl;
}

void PhoneBook::searchContact() const
{
	int index;
	std::cout << "Enter the index of the contact you want to view: ";
	std::cin >> index;
	displayContactDetails(index);
}

