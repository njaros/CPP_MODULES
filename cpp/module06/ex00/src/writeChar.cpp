/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeChar.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:11:36 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 17:26:50 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"

void	writeChar(std::string str)
{
	char	castChar;

	if (str.compare("nan") || str.compare("NaN"))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (std::atoi(str.data()) > MAX_CHAR || )
}