/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commonUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:49:34 by njaros            #+#    #+#             */
/*   Updated: 2022/05/30 11:05:55 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"

bool	isNum(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isLitteralException(std::string str, int &type)
{
	if (!str.compare("NAN") || !str.compare("-INF") || !str.compare("+INF"))
		return (1);
	if (!str.compare("-INFF") || !str.compare("+INFF") || !str.compare("NANF"))
	{
		type = FLOAT;
		return (1);
	}
	return (0);
}

std::string	toUpperStr(std::string str)
{
	int			i;
	std::string	Upped;

	i = -1;
	while (str.data()[++i])
		Upped += (char)std::toupper(str.data()[i]);
	return (Upped);
}

void	eraseFirstsZeros(std::string &str)
{
	std::string::size_type	idx;

	idx = 0;
	if (str.data()[idx] == '-')
		idx++;
	while (str.data()[idx] == '0' && str.data()[idx + 1] && str.data()[idx + 1] != '.')
	{
		str.erase(idx, 1);
	}
}