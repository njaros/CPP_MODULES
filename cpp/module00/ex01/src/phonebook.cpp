/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:28:41 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 15:51:17 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << std::endl << "Hello user, I can help you to remember..." << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Goodbye user, let's forget together" << std::endl << std::endl;
	return;
}

void	PhoneBook::getNotEmptyLine(std::string *buffer)
{
	secureGetline(buffer);
	while (buffer->empty())
	{
		std::cout << std::endl << "You can't let nothing, retry : ";
		secureGetline(buffer);
	}
}

void	PhoneBook::ftAdd(int i)
{
	std::string	buffer;

	std::cout << "Enter the contact's first name : ";
	this->getNotEmptyLine(&buffer);
	this->_contact[i].set_value(FIRSTNAME_, buffer);
	std::cout << std::endl << "Enter the contact's last name : ";
	this->getNotEmptyLine(&buffer);
	this->_contact[i].set_value(LASTNAME_, buffer);
	std::cout << std::endl << "Enter the contact's nickname : ";
	this->getNotEmptyLine(&buffer);
	this->_contact[i].set_value(NICKNAME_, buffer);
	std::cout << std::endl << "Enter the contact's phone number : ";
	this->getNotEmptyLine(&buffer);
	this->_contact[i].set_value(PHONENUMBER_, buffer);
	std::cout << std::endl << "Enter the contact's darkest secret : ";
	this->getNotEmptyLine(&buffer);
	this->_contact[i].set_value(DARKESTSECRET_, buffer);
	std::cout << std::endl << "New contact added" << std::endl;
	return;
}

// I only seen after I finished my program that I could use iomanip library
// or cout.fill + cout.widht to do the next fonction easier.
// I keep it like this because it works.
void	PhoneBook::streamRepertory(int i)
{
	int	j;
	int	val;
	int	strLenght;

	j = -1;
	std::cout << std::endl << "_____________________________________________";
	std::cout << std::endl << "|   INDEX  |FIRST NAME|LAST  NAME| NICKNAME |" << std::endl;
	while (++j < i)
	{
		val = 0;
		std::cout << "|" << "     " << j + 1 << "    " << "|";
		while (++val <= 3)
		{
			strLenght = this->_contact[j].get_value(val).length();
			std::cout << std::setw(10);
			std::cout << std::right;
			if (strLenght > 10)
				std::cout << this->_contact[j].get_value(val).substr(0, 9).append(".");
			else
				std::cout << this->_contact[j].get_value(val);
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl << std::endl;
}

void	PhoneBook::ftSearch(int i)
{
	std::string	buffer;
	int			index;

	if (!i)
	{
		std::cout << "Theyre is no contact I remember yet" << std::endl;
		return;
	}
	this->streamRepertory(i);
	std::cout << "Enter the contact's index to get more details : ";
	secureGetline(&buffer);
	while (buffer.size() > 1 || buffer.compare("1") < 0 || buffer.data()[0] > i + '0')
	{
		std::cout << std::endl << "you said : " << buffer;
		std::cout << std::endl << "I didn't anderstand, please retry : ";
		secureGetline(&buffer);
	}
	index = buffer[0] - '0' - 1;
	std::cout << std::endl << "First name : " << this->_contact[index].get_value(FIRSTNAME_);
	std::cout << std::endl << "Last name : " << this->_contact[index].get_value(LASTNAME_);
	std::cout << std::endl << "Nickname : " << this->_contact[index].get_value(NICKNAME_);
	std::cout << std::endl << "Phone number : " << this->_contact[index].get_value(PHONENUMBER_);
	std::cout << std::endl << "Darkest secret : " << this->_contact[index].get_value(DARKESTSECRET_);
	std::cout << std::endl;
	return;
}
