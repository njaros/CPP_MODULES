/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:39:36 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:39:37 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

void	secureGetline(std::string *buffer)
{
	while (!std::getline(std::cin, *buffer))
	{
			std::cin.clear();
			clearerr(stdin);
	}
}
