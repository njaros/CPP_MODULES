
#include "phonebook.hpp"

Contact::Contact(void)
{
	std::cout << "A contact slot has been created" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "A contact has been forgotten" << std::endl;
	return;
}

void	Contact::meminit(void)
{
	memset(this->_firstName, 0, 32);
	memset(this->_lastName, 0, 32);
	memset(this->_nickName, 0, 32);
	memset(this->_phoneNumber, 0, 32);
	memset(this->_darkestSecret, 0, 512);
	return;
}

void	Contact::set_value(int context, char *str)
{
	if (context == FIRSTNAME_)
		strncpy(this->_firstName, str, 31);
	else if (context == LASTNAME_)
		strncpy(this->_lastName, str, 31);
	else if (context == NICKNAME_)
		strncpy(this->_nickName, str, 31);
	else if (context == PHONENUMBER_)
		strncpy(this->_phoneNumber, str, 31);
	else
		strncpy(this->_darkestSecret, str, 511);
	return;
}

void	Contact::get_value(int context)	const
{
	if (context == FIRSTNAME_)
		std::cout << this->_firstName;
	else if (context == LASTNAME_)
		std::cout << this->_lastName;
	else if (context == NICKNAME_)
		std::cout << this->_nickName;
	else if (context == PHONENUMBER_)
		std::cout << this->_phoneNumber;
	else
		std::cout << this->_darkestSecret;
}
