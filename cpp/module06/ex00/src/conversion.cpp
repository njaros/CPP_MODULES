/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:02:20 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 17:29:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/writingInType.hpp"

int	main(int ac, char **av)
{
	std::string	toConvert;
	if (ac != 2)
	{
		std::cout << "I/O error" << std::endl;
		return (1);
	}
	toConvert = av[1];
	if (!isLitteral(toConvert))
	{
		std::cout << "the entry MUST BE a litteral C++ !!" << std::endl;
		return (1);
	}
	std::cout << toConvert << std::endl;
	std::cout << "char : " << (char)std::atoi(toConvert.data()) << std::endl;
	std::cout << "int : " << std::atoi(toConvert.data()) << std::endl;
	std::cout << "float : " << std::atof(toConvert.data()) << std::endl;
	std::cout << "double : " << std::atof(toConvert.data()) << std::endl;

	std::cout << MAX_INT << std::endl;
	std::cout << MAX_DOUBLE << std::endl;
	std::cout << MAX_FLOAT << std::endl;
	return (0);
}