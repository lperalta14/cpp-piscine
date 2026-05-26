#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact{
private:
	std::string name;
	std::string lastname;
	std::string phonenumber;
	std::string nickname;
	std::string darkestsecret;
public:
	Contact();
	~Contact();
	std::string getName();
	std::string getLastName();
	std::string getPhoneNumber();
	std::string getNickName();
	std::string getDarkestSecret();
	void setName(const std::string& name);
	void setLastName(const std::string& lastname);
	void setPhoneNumber(const std::string& phonenumber);
	void setNickName(const std::string& nickname);
	void setDarkestSecret(const std::string& darkestsecret);
};

#endif