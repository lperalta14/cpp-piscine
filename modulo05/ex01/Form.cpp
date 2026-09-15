#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default"),_signed(0), _gradeSign(1), _gradeExe(1)
{
}

Form::Form(const std::string& name, int gradeSign, int gradeExe) : _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe), _signed(0)
{
    if (this->_gradeSign < 1 || this->_gradeExe <1)
        throw GradeTooHighException();
    else if (this->_gradeSign > 150 || this->_gradeExe >150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe), _signed(other._signed)
{ 
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return(*this);
}

Form::~Form()
{}

std::string	Form::getName() const
{
    return(this->_name);
}

bool		Form::getSigned() const
{
    return(this->_signed);
}

int			Form::getGradeSign() const
{
    return(this->_gradeSign);
}

int			Form::getGradeExe() const
{
    return(this->_gradeExe);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    int grade = bureaucrat.getGrade();
    if (grade > this->_gradeSign)
        throw GradeTooLowException();
    this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName() << " signed : " << form.getSigned() << ", grade required to sign: " << form.getGradeSign() << ", grade required to execute: " << form.getGradeExe() << "."; 
    return out;
}