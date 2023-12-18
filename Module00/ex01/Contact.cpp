#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
	// Initialise les membres à des valeurs par défaut
	FirstName = "";
	LastName = "";
	Nickname = "";
	PhoneNumber = "";
	DarkestSecret = "";
}

Contact::Contact(const std::string& first, const std::string& last, const std::string& nick,
			const std::string& phone, const std::string& secret)
			{
	// Initialise les membres avec les valeurs passées en paramètres
	FirstName = first;
	LastName = last;
	Nickname = nick;
	PhoneNumber = phone;
	DarkestSecret = secret;
}

void Contact::displayShortInfo(int index) const
{
	std::cout << index << " | ";
	std::cout << FirstName.substr(0, 10) << " | ";
	std::cout << LastName.substr(0, 10) << " | ";
	std::cout << Nickname.substr(0, 10) << std::endl;
}

void Contact::displayFullInfo() const
{
	// Affiche toutes les informations du contact
	std::cout << "First Name: " << FirstName << std::endl;
	std::cout << "Last Name: " << LastName << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone Number: " << PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}

bool Contact::isEmpty() const
{
	// Vérifie si le contact est vide (aucune information)
	return (FirstName.empty() && LastName.empty() && Nickname.empty() &&
			PhoneNumber.empty() && DarkestSecret.empty());
}

void Contact::setContact(const std::string& first, const std::string& last, const std::string& nick,
					const std::string& phone, const std::string& secret)
{
	// Modifie les informations du contact avec les nouvelles données
	FirstName = first;
	LastName = last;
	Nickname = nick;
	PhoneNumber = phone;
	DarkestSecret = secret;
}

std::string Contact::getFirstName() const
{
	return FirstName;
}

std::string Contact::getLastName() const
{
	return LastName;
}
std::string Contact::getNickname() const
{
	return Nickname;
}

std::string Contact::getPhoneNumber() const
{
	return PhoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return DarkestSecret;
}
