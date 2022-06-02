/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:06:53 by njaros            #+#    #+#             */
/*   Updated: 2022/06/02 15:07:20 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>

void	display(int i)
{
	std::cout << i << " | ";
}

int main (int ac, char **av)
{
	unsigned int	idx;

	std::cout << "nbr of args : " << ac - 1 << std::endl;
	Span test(ac - 1);
	idx = 0;
	while (av[++idx])
	{
		try
		{
			test.addNumber(std::atoi(av[idx]));	
		}
		catch (const char* &e)
		{
			std::cout << e << std::endl;
		}
	}
	std::cout << "longestSpan = ";
	try
	{
		std::cout << test.longestSpan() << std::endl;
	}
	catch (const char* &e)
	{
		std::cout << e << std::endl;
	} 
	std::cout << "shortestSpan = " ;
	try
	{
		std::cout << test.shortestSpan() << std::endl;
	}
	catch (const char* &e)
	{
		std::cout << e << std::endl;
	}

	std::cout << std::endl << std::endl <<  "subject test" << std::endl << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}