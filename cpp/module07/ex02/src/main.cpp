/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:57:56 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 16:43:41 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main()
{
	Array<float> A(4);
	Array<float> B = A;
	Array<std::string> strs(5);

	A[2] = 3.7;
	std::cout << A[2] << std::endl;
	std::cout << B[2] << std::endl;
	B = A;
	std::cout << B[2] << std::endl;
	try
	{
		A[4] = 7;
	}
	catch (InvalidIndexException &e)
	{
		std::cout << e.what() << std::endl; 
	}
	strs[0] = "coucou";
	std::cout << strs[0] << std::endl;

	Array<char> crash(0);
	try
	{
		crash[0] = 'u';
	}
	catch (InvalidIndexException &e)
	{
		std::cout << e.what() << std::endl; 
	}
}