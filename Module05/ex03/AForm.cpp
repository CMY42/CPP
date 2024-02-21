#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm &copy)
{
	_isSigned = copy._isSigned; //_name, _gradeToSign et _gradeToExecute ne sont pas assignés car ils sont constants
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << " is " << (form.getIsSigned() ? "" : "not ") << "signed, grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return out;
}
