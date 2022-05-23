/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:43:18 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 11:16:00 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main(void)
{
	int			loop;
	ClapTrap	a;
	ClapTrap	b("njaros");
	ClapTrap	c(b);
	ClapTrap	bullier("bullier");

	loop = -1;
	while (++loop < 12)
	{
		if (a.getEp())
		{
			a.attack(b.getName());
			b.takeDamage(a.getAd());
		}
		else
			a.attack(b.getName());
	}
	c.takeDamage(80);
	loop = -1;
	while (++loop < 10)
	{
		bullier.attack(c.getName());
		c.takeDamage(bullier.getAd());
		c.beRepaired(3);
	}
	b.takeDamage(9);
	bullier.takeDamage(9);
	bullier.beRepaired(9);
	loop = -1;
	while (++loop < 11)
		b.beRepaired(2);
	return (0);
}
