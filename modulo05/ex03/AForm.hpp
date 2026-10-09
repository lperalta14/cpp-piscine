#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string   _name;
	bool                _signed;
	const int           _gradeSign;
	const int           _gradeExe;
protected:
    virtual void executeAction() const = 0;
public:
	AForm();
	AForm(const std::string& name, int gradeSign, int gradeExe);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExe() const;
	
	void		beSigned(Bureaucrat const &bureaucrat);
	void execute(Bureaucrat const & executor) const;
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

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif