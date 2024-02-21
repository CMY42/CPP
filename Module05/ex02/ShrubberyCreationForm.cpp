#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	_target = copy._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file <<      "      ||      " << std::endl;
	file <<      "      ||      " << std::endl;
	file << "   //^^^^^^\\\\ " << std::endl;
	file << "  //\\||||||/\\\\" << std::endl;
	file << " //\\//||||\\//\\\\" << std::endl;
	file << "      ||      " << std::endl;
	file <<      "      ||      " << std::endl;
	file <<      "      ||      " << std::endl;
	file <<      "      ||      " << std::endl;
	file << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return "File could not be opened";
}
