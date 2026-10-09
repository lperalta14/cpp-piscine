#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Default"),_signed(0), _gradeSign(1), _gradeExe(1)
{
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExe) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
    if (this->_gradeSign < 1 || this->_gradeExe <1)
        throw GradeTooHighException();
    else if (this->_gradeSign > 150 || this->_gradeExe >150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe)
{ 
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return(*this);
}

AForm::~AForm()
{}

std::string	AForm::getName() const
{
    return(this->_name);
}

bool		AForm::getSigned() const
{
    return(this->_signed);
}

int			AForm::getGradeSign() const
{
    return(this->_gradeSign);
}

int			AForm::getGradeExe() const
{
    return(this->_gradeExe);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    int grade = bureaucrat.getGrade();
    if (grade > this->_gradeSign)
        throw GradeTooLowException();
    this->_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!_signed)
        throw GradeTooLowException();
    if (executor.getGrade() > _gradeExe)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
    out << AForm.getName() << " signed : " << AForm.getSigned() << ", grade required to sign: " << AForm.getGradeSign() << ", grade required to execute: " << AForm.getGradeExe() << "."; 
    return out;
}