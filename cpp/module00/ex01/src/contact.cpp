/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:28:53 by njaros            #+#    #+#             */
/*   Updated: 2022/05/13 18:28:54 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


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

void	Contact::set_value(int context, std::string str)
{
	int	lenght;

	if (context == FIRSTNAME_)
	{
		lenght = str.copy(this->_firstName, 31, 0);
		this->_firstName[lenght] = '\0';
	}
	else if (context == LASTNAME_)
	{
		lenght = str.copy(this->_lastName, 31, 0);
		this->_lastName[lenght] = '\0';
	}
	else if (context == NICKNAME_)
	{
		lenght = str.copy(this->_nickName, 31, 0);
		this->_nickName[lenght] = '\0';

	}
	else if (context == PHONENUMBER_)
	{
		lenght = str.copy(this->_phoneNumber, 31, 0);
		this->_phoneNumber[lenght] = '\0';
	}	
	else
	{
		lenght = str.copy(this->_darkestSecret, 511, 0);
		this->_darkestSecret[lenght] = '\0';
	}
	return;
}

char	*Contact::get_value(int context)
{
	if (context == FIRSTNAME_)
		return (this->_firstName);
	else if (context == LASTNAME_)
		return (this->_lastName);
	else if (context == NICKNAME_)
		return (this->_nickName);
	else if (context == PHONENUMBER_)
		return (this->_phoneNumber);
	else
		return (this->_darkestSecret);
}
