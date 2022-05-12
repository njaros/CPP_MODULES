/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:41:11 by njaros            #+#    #+#             */
/*   Updated: 2022/05/11 18:04:45 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <cstring>

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

		void	meminit(void);
		void	set_value(int context, char *str);
		void	get_value(int context)	const;

	private :

		char	_firstName[32];
		char	_lastName[32];
		char	_nickName[32];
		// phoneNumber is char[] because the user entry is char[]
		char	_phoneNumber[32];
		char	_darkestSecret[512];
	
};

class PhoneBook
{
	public :
	
		PhoneBook(void);
		~PhoneBook(void);

		void	ftAdd(int i);
		void	ftSearch(int i)	const;

	private :

		Contact	_contact[8];

};

#endif