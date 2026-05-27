#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook{
private:
	Contact	_contacts[8];
	int		_count;
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
};

#endif