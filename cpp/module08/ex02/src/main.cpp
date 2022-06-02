/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:59:36 by njaros            #+#    #+#             */
/*   Updated: 2022/06/02 16:24:19 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int	main()
{
	MutantStack<std::string>	test;

	test.push("coucou");
	test.push("crotte");
	test.push("chemise");
	test.push("");
	test.push("owfsbvouwesjkbeiounjkbesiufbesjkveiuwbfeksviukrbgouw");
	test.push("o");

	MutantStack<std::string>::iterator	it;
	it = test.begin();

	std::cout << *test.begin() << " | " << *test.end() << std::endl;
	while (it != test.end())
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	return 0;
}