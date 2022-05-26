/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isLitteral.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:30:16 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 17:46:36 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"

bool	isLitteral(std::string str)
{
	int	i;

	if (str.empty())
		return (0);
	if (str.length() == 1)
		return (1);
	i = 0;
	if (str.data()[i] == '-')
		i++;
	while (str.data()[i] && std::is_str.data()[i])
	{
		if 
	}	
}