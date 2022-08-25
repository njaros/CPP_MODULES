/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:59:36 by njaros            #+#    #+#             */
/*   Updated: 2022/08/25 09:34:54 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

struct pixel
{
	int	x;
	int	y;
	int	z;
};

std::ostream	&operator<<( std::ostream &o, pixel const &p )
{
	o << "x = " << p.x << " y = " << p.y << " z = " << p.z;
	return (o);
}

int	main()
{
	MutantStack<std::string>	test;

	test.push("coucou");
	test.push("crotte");
	test.push("chemise");
	test.push("");
	test.push("owfsbvouwesjkbeiounjkbesiufbesjkveiuwbfeksviukrbgouw");
	test.push("o");

	std::cout << test.top() << std::endl;
	MutantStack<std::string>::iterator	it;
	it = test.begin();

	std::cout << "\n\n <--------- reading test --------->\n\n";

	while (it != test.end())
	{

		std::cout << *it << " | ";
		it++;
	}
	std::cout << "\n\n <--------- const_iterator test --------->\n\n";
	
	MutantStack<std::string>::const_iterator constIt;
	constIt = test.begin() + 1;
	std::cout << *constIt;
	std::cout << "\n\n <--------- other iterator tests --------->\n\n";

	MutantStack<pixel>	pixelStack;
	for (int i = 0; i < 7; i++)
	{
		pixel	a;
		a.x = i;
		a.y = i;
		a.z = i;
		pixelStack.push(a);
	}
	MutantStack<pixel>::iterator	it2;
	it2 = pixelStack.begin();
	std::cout << it2[4] << std::endl;
	std::cout << ++it2->x << std::endl;

	return (0);
}