#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact();
	~Contact();

	void setContactInfo();
	void displayContactInfo(int index) const;
	std::string truncateText(const std::string& text, size_t width) const;
	void displayFullContactInfo() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
