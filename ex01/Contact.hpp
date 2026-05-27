#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact{
private:
	std::string _name;
	std::string _lastName;
	std::string _phoneNumber;
	std::string _nickName;
	std::string _darkestSecret;
public:
	Contact();
	~Contact();
	std::string getName();
	std::string getLastName();
	std::string getPhoneNumber();
	std::string getNickName();
	std::string getDarkestSecret();
	void setName(const std::string& _name);
	void setLastName(const std::string& _lastName);
	void setPhoneNumber(const std::string& _phoneNumber);
	void setNickName(const std::string& _nickName);
	void setDarkestSecret(const std::string& _darkestSecret);
};

#endif