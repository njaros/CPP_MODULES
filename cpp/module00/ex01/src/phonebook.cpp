
#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		this->_contact[i].meminit();
		std::cout << "slot memory : " << i << " initialized" << std::endl;
	}
	std::cout << "Hello user, I can help you to remember..." << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Goodbye user, let's forget together" << std::endl;
	return;
}

void	PhoneBook::ftAdd(int i)
{
	char	buffer[512];

	std::cout << "Enter the contact's first name :";
	std::cin >> buffer;
	this->_contact[i].set_value(FIRSTNAME_, buffer);
	std::cout << std::endl << "Enter the contact's last name :";
	std::cin >> buffer;
	this->_contact[i].set_value(LASTNAME_, buffer);
	std::cout << std::endl << "Enter the contact's nickname :";
	std::cin >> buffer;
	this->_contact[i].set_value(NICKNAME_, buffer);
	std::cout << std::endl << "Enter the contact's phone number :";
	std::cin >> buffer;
	this->_contact[i].set_value(PHONENUMBER_, buffer);
	std::cout << std::endl << "Enter the contact's darkest secret :";
	std::cin >> buffer;
	this->_contact[i].set_value(DARKESTSECRET_, buffer);
	std::cout << std::endl << "New contact added" << std::endl;
	return;
}

void	PhoneBook::ftSearch(int i)	const
{
	char	buffer[2];
	int		j;
	int		index;

	if (!i)
	{
		std::cout << "They're is no contact I remember yet" << std::endl;
		return;
	}
	j = -1;
	while (++j < i)
	{
		std::cout << " | " << j << " | ";
		this->_contact[j].get_value(FIRSTNAME_);
		std::cout << " | " ;
		this->_contact[j].get_value(LASTNAME_);
		std::cout << " | ";
		this->_contact[j].get_value(NICKNAME_);
		std::cout << " | ";
		std::cout << std::endl;
	}
	std::cout << "Enter the contact's index to get more details :";
	std::cin >> buffer;
	while (buffer[1] || buffer[0] < '0' || buffer[0] >= i + '0')
	{
		std::cout << std::endl << "I didn't anderstand, please retry :";
		std::cin >> buffer;
	}
	index = buffer[0] - '0';
	std::cout << std::endl << "First name : ";
	this->_contact[index].get_value(FIRSTNAME_);
	std::cout << std::endl << "Last name : ";
	this->_contact[index].get_value(LASTNAME_);
	std::cout << std::endl << "Nickname : ";
	this->_contact[index].get_value(NICKNAME_);
	std::cout << std::endl << "Phone number : ";
	this->_contact[index].get_value(PHONENUMBER_);
	std::cout << std::endl << "Darkest secret : ";
	this->_contact[index].get_value(DARKESTSECRET_);
	std::cout << std::endl;
	return;
}
