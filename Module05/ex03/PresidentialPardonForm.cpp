#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	_target = copy._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

