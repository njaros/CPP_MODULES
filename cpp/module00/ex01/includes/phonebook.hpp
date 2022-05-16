/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:41:11 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 16:15:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string.h>
# include <stdio.h>
# include <iomanip>

# define FIRSTNAME_ 1
# define LASTNAME_ 2
# define NICKNAME_ 3
# define PHONENUMBER_ 4
# define DARKESTSECRET_ 5

class Contact
{
	public :

		Contact(void); //Constructeur
		~Contact(void); //Destructeur

		void		set_value(int context, std::string str);
		std::string	get_value(int context);

	private :

		// I could use std::string instead of char[]
		// anyway I learned a lot about string member fonctions to convert to char[].
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	
};

class PhoneBook
{
	public :
	
		PhoneBook(void);
		~PhoneBook(void);

		void	ftAdd(int i);
		void	ftSearch(int i);

	private :

		void	streamRepertory(int i);
		void	getNotEmptyLine(std::string *buffer);
		Contact	_contact[8];

};


// A secure fonction to counter ctrl + D
void	secureGetline(std::string *buffer);

#endif