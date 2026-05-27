#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0) {	
}

static std::string getInput(const std::string& prompt)
{
	std::string input;

	while(input.empty())
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
	}
	return input;
}

void PhoneBook::addContact()
{
	Contact contact;

	contact.setName(getInput("¿qué nombre le ponemos a la criatura?"));
	contact.setLastName(getInput("¿y el apellido?"));
	contact.setNickName(getInput("¿Un mote?"));
	contact.setPhoneNumber(getInput("¿Me das tu número?"));
	contact.setDarkestSecret(getInput("Escribeme tú más oscuro secreto"));
	this->_contacts[_count % 8] = contact;
	_count++;
}


PhoneBook::~PhoneBook(){}