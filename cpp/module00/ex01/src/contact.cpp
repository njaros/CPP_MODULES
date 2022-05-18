/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:28:53 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 15:40:30 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

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
	if (context == FIRSTNAME_)
		this->_firstName = str;
	else if (context == LASTNAME_)
		this->_lastName = str;
	else if (context == NICKNAME_)
		this->_nickName = str;
	else if (context == PHONENUMBER_)
		this->_phoneNumber = str;
	else
		this->_darkestSecret = str;
	return;
}

std::string	Contact::get_value(int context)
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
