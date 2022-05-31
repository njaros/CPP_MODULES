/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:14:50 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 13:49:41 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

void	plusUn(int &val)
{
	val += 1;
}

void	toUpperChar(char &c)
{
	c = (char)std::toupper(c);
}

int	main(void)
{
	int tab[] = {1, 2, 3, 4};
	int	*ptr = &tab[0];
	iter(ptr, 4, plusUn);
	std::cout << tab[0] << tab[1] << tab[2] << tab[3] << std::endl;

	/*-----------------------------*/

	char	str[] = "FraiseD444333oibs";
	iter(str, std::strlen(str), toUpperChar);
	std::cout << str << std::endl;
}
