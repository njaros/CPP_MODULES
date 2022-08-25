/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:06:53 by njaros            #+#    #+#             */
/*   Updated: 2022/08/25 09:13:19 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>
#include <vector>

int main (int ac, char **av)
{

	std::cout << "\n<-------- argv test --------->\n\n";

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


	std::cout << "\n\n<--------- custom test ---------->\n\n";

	int		tab[] = {0, 455, 15, 30, -20, 311};
	int		tab2[] = {15, 180, 795, -89666, 40, 42, 43, 44, 789, 987, 963, 231, 741, 147};
	//int		tab3[] = {1, 2, 3, 4, 5, 6, 7};
	Span	testTab(15);
	testTab.insert(tab, tab + 5);
	testTab.insert(tab2 + 1, tab2 + 10);
	//testTab.insert(tab3, tab3 + 4);
	std::cout << "shortest span : " << testTab.shortestSpan() << std::endl;
	std::cout << "longest span : " << testTab.longestSpan() << std::endl;

	std::cout << "\n\n<--------- subject test ---------->\n\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "longest span : " << sp.longestSpan() << std::endl;

	std::cout << "\n\n<--------- lot of ints test --------->\n\n";
	std::vector<int>	tonsOfInts;
	int		lenght;
	lenght = 50; // <--- you can change the lenght here
	Span	longSpan(lenght);
	for (int i = 0; i < lenght; i++)
		tonsOfInts.push_back(i);
	longSpan.insert(tonsOfInts.begin(), tonsOfInts.end());
	std::cout << "shortest span : " << longSpan.shortestSpan() << std::endl;
	std::cout << "longest span : " << longSpan.longestSpan() << std::endl;

	return (0);
}