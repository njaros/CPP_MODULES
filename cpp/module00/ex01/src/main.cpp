/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:28:47 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 09:10:12 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"

int	routine(void)
{
	PhoneBook	redfish;
	std::string	buffer;
	int			roll;
	int			memUsed;

	memUsed = 0;
	roll = 0;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "You can type \"ADD\", \"SEARCH\", \"EXIT\"";
		std::cout << " if you want to add a contact, search a contact or exit (not a contact) : ";
		secureGetline(&buffer);
		std::cout << std::endl;
		if (!buffer.compare("ADD"))
		{
			redfish.ftAdd(roll);
			if (roll == 7)
				roll = 0;
			else
				roll++;
			if (memUsed < 8)
				memUsed++;
		}
		else if (!buffer.compare("SEARCH"))
			redfish.ftSearch(memUsed);
		else if (!buffer.compare("EXIT"))
			return (0);
	}
}

int	main(void)
{
	int	i;

	system("clear");
	std::cout << std::endl;
	i = routine();
	std::cout << std::endl;
	return (i);
}
