#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook();

	// Ajoute un nouveau contact
	void addContact(const std::string& first, const std::string& last, const std::string& nick,
					const std::string& phone, const std::string& secret);

	// Affiche tous les contacts avec un index
	void displayContacts() const;

	// Affiche les détails complets d'un contact
	void displayContactDetails(int index) const;

	// Recherche un contact par index et affiche ses détails
	void searchContact() const;
};

#endif // PHONEBOOK_HPP
