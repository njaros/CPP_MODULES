/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:06:53 by njaros            #+#    #+#             */
/*   Updated: 2022/08/23 17:57:09 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>
#include <vector>

int main (int ac, char **av)
{
	unsigned int		idx;
	std::vector<int>	argv;

	Span test(ac - 1);
	idx = 0;
	while (av[++idx])
		argv.push_back(std::atoi(av[idx]));
	test.insert(argv.begin(), argv.end());
	std::cout << "longestSpan = ";
	try
	{
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "shortestSpan = " ;
	try
	{
		std::cout << test.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl <<  "<--------- subject test ---------->\n\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "longest span : " << sp.longestSpan() << std::endl;
	return (0);
}