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

# include "../includes/Contact.hpp"

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