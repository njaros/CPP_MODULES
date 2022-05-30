/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isLitteral.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:30:16 by njaros            #+#    #+#             */
/*   Updated: 2022/05/30 15:10:23 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"

bool	isLitteral(std::string str, int &type)
{
	std::string::size_type	idx;

	idx = 0;
	type = DOUBLE;
	if (str.empty())
		return (0);
	if (str.length() == 1)
	{
		if (str.data()[0] >= '0' && str.data()[0] <= '9')
			type = INT;
		else
			type = CHAR;
		return (1);
	}
	if (isLitteralException(str , type))
		return (1);
	if (str.data()[idx] == '-')
		idx++;
	if (!isNum(str.data()[idx]))
		return (0);
	while (isNum(str.data()[idx]))
		idx++;
	if (!str.data()[idx])
	{
		type = INT;
		return (1);
	}
	if (str.data()[idx] != '.')
		return (0);
	idx++;
	if (!isNum(str.data()[idx]))
		return (0);
	while (isNum(str.data()[idx]))
		idx++;
	if (str.data()[idx] == 'F')
	{
		type = FLOAT;
		idx++;
	}
	if (str.data()[idx])
		return (0);
	return (1);
}
