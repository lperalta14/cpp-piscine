#include "Contact.hpp"

Contact::Contact(){}

std::string Contact::getName()
{
	return (name);
}

std::string Contact::getLastName()
{
	return lastname;
}

std::string Contact::getNickName()
{
	return nickname;
}

std::string Contact::getPhoneNumber()
{
	return phonenumber;
}

std::string Contact::getDarkestSecret()
{
	return darkestsecret;
}
void Contact::setName(const std::string& name)
{
	this->name = name;
}

void Contact::setLastName(const std::string& lastname)
{
	this->lastname = lastname;
}

void Contact::setNickName(const std::string& nickname)
{
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phonenumber)
{
	this->phonenumber = phonenumber;
}

void Contact::setDarkestSecret(const std::string& darkestsecret)
{
	this->darkestsecret = darkestsecret;
}

Contact::~Contact(){}
