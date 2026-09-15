#include "AForm.hpp"

AForm::AForm(void)
	: _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm(void)
{
}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->action();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high (max grade is 1)");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low (min grade is 150)");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form \"" << form.getName() << "\", signed: "
		<< (form.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute() << ".";
	return (os);
}
