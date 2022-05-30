/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:02:20 by njaros            #+#    #+#             */
/*   Updated: 2022/05/30 16:48:54 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"
#include "../includes/MultiType.hpp"

int	main(int ac, char **av)
{
	std::string	toConvert;
	int			type;

	if (ac != 2)
	{
		std::cout << "Input error" << std::endl;
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
	MultiType tool(toConvert, type);
	tool.displayChar();
	tool.displayInt();
	tool.displayFloat();
	tool.displayDouble();
	return (0);
}