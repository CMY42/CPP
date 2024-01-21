#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setContactInfo()
{
	std::cout << "Enter first name: ";
	std::cin >> firstName;

	std::cout << "Enter last name: ";
	std::cin >> lastName;

	std::cout << "Enter nickname: ";
	std::cin >> nickname;

	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;

	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
}

void Contact::displayContactInfo(int index) const
{
	std::cout << "| " << std::setw(8) << index << " | " << std::setw(10) << std::right << truncateText(firstName, 10) << " | "
	<< std::setw(10) << std::right << truncateText(lastName, 10) << " | " << std::setw(10) << std::right << truncateText(nickname, 10) << " |"
	<< std::endl;
}

std::string Contact::truncateText(const std::string& text, size_t width) const
{
	return (text.length() > width) ? (text.substr(0, width - 1) + '.') : text;
}

void Contact::displayFullContactInfo() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
