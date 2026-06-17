#include "Contact.hpp"

Contact::Contact(){}

std::string Contact::getName()
{
	return (_name);
}

std::string Contact::getLastName()
{
	return _lastName;
}

std::string Contact::getNickName()
{
	return _nickName;
}

std::string Contact::getPhoneNumber()
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return _darkestSecret;
}
void Contact::setName(const std::string& name)
{
	this->_name = name;
}

void Contact::setLastName(const std::string& lastname)
{
	this->_lastName = lastname;
}

void Contact::setNickName(const std::string& nickname)
{
	this->_nickName = nickname;
}

void Contact::setPhoneNumber(const std::string& phonenumber)
{
	this->_phoneNumber = phonenumber;
}

void Contact::setDarkestSecret(const std::string& darkestsecret)
{
	this->_darkestSecret = darkestsecret;
}

Contact::~Contact(){}
