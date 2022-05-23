/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:11 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:42:12 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int ac, char **av)
{
	Harl		pouet;
	int			i;
	std::string	str;
	
	(void) ac;
	i = 0;
	while (av[++i])
	{
		str = av[i];
		pouet.complain(str);
	}
	return 0;
}
