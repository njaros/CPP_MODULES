/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringToChar.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:11:36 by njaros            #+#    #+#             */
/*   Updated: 2022/05/27 14:32:10 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"

bool	isChar(std::string str)
{
	if (str.length() == 1)
		return (1);
	return (0);
}

void	stringToChar(std::string str)
{
	char	castChar;
	int		val;

	std::cout << "char: ";
	if (isLitteralException(str, val))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isChar(str))
	{
		std::cout << str << std::endl;
		return ;
	}
	
}
