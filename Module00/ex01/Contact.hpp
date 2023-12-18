#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;

public:
	Contact();
	Contact(const std::string& first, const std::string& last, const std::string& nick,
			const std::string& phone, const std::string& secret); // Constructeur surchargé

	// Méthodes pour accéder et manipuler les données des contacts
	void displayShortInfo(int index) const;
	void displayFullInfo() const;
	bool isEmpty() const;
	void setContact(const std::string& first, const std::string& last, const std::string& nick,
				const std::string& phone, const std::string& secret);
	// ... (d'autres méthodes nécessaires)

	// Méthodes pour accéder aux données des contacts
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif // CONTACT_HPP
