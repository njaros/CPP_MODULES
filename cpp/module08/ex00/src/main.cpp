/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:36:57 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 18:39:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>
#include <list>

int main(int ac, char **av)
{
	std::vector<int> a(12);

	if (ac != 2)
		return 1;
	a[0] = 4;
	a[8] = 20;
	a[11] = -8;
	a[12] = 42;
	std::cout << "vector test : " << std::endl;
	try
	{
		std::cout << easyfind(a, std::atoi(av[1])) << " is the postiton of " << av[1] << std::endl;
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
	}

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(1);
	lst.push_back(-8);
	std::cout << std::endl << "list test : " << std::endl;
	try
	{
		std::cout << easyfind(lst, std::atoi(av[1])) << " is the postiton of " << av[1] << std::endl;
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
	}

	return (0);
}