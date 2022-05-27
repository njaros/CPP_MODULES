/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:02:20 by njaros            #+#    #+#             */
/*   Updated: 2022/05/27 16:56:32 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"
#include "../includes/MultiType.hpp"

int	main(int ac, char **av)
{
	std::string	toConvert;
	MultiType	tool;
	int			type;

	if (ac != 2)
	{
		std::cout << "I/O error" << std::endl;
		return (1);
	}
	toConvert = av[1];
	if (toConvert.length() > 1)
		toConvert = toUpperStr(toConvert);
	if (!isLitteral(toConvert, type))
	{
		std::cout << "the entry MUST BE a litteral C++ !!" << std::endl;
		return (1);
	}
	eraseFirstsZeros(toConvert);
	switch(type)
	{
		case (CHAR) : 
			tool = MultiType(toConvert.data()[0]);
			break ;
		case (INT) :
			tool = MultiType(std::stoi(toConvert.data()));
			break;
		case (FLOAT) :
			tool = MultiType(std::stof(toConvert.data()));
			break;
		default :
			tool = MultiType(std::stod(toConvert.data()));
	}
	
	return (0);
}