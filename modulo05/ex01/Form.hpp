#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string   _name;
	bool                _signed;
	const int           _gradeSign;
	const int           _gradeExe;
public:
	Form();
	Form(const std::string& name, int gradeSign, int gradeExe);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExe() const;
	
	void		beSigned(Bureaucrat const &bureaucra);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif