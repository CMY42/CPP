#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContacts() const;

private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int numContacts;
};

#endif
