#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const &executor) const;

	class FileNotOpenException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif
