#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0) {	
}

static std::string getInput(const std::string& prompt)
{
	std::string input;

	while(input.empty())
	{
		std::cout << prompt << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}
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

void PhoneBook::searchContact()
{
	int limit = (_count < 8) ? _count : 8;

	for (int i = 0; i < limit; i++)
	{
		std::cout << std::right << std::setw(10) << std::substr(_contacts[i].getName()) << "|";
		std::cout << std::right << std::setw(10) << _contacts[i].getLastName() << "|";
	}
}
Vas bien con la estructura, pero std::substr no existe — substr es un método de std::string, no de std. Se llama así:
cpp_contacts[i].getName().substr(0, 9)
Pero recuerda que substr solo lo usas si el string tiene más de 10 caracteres — si no, lo imprimes tal cual. Esa es la lógica de truncado que te mencioné antes.
Te propongo hacer una función estática auxiliar, igual que hiciste con getInput:
cppstatic std::string truncate(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}
¿Lo entiendes? Si el string tiene más de 10 caracteres, devuelve los primeros 9 más un . — total 10. Si no, lo devuelve tal cual.
Añade esa función y úsala en el std::cout. ¿Cómo quedaría la línea del nombre usando truncate?
PhoneBook::~PhoneBook(){}