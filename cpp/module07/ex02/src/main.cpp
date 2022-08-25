/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:57:56 by njaros            #+#    #+#             */
/*   Updated: 2022/08/25 14:14:04 by njaros           ###   ########lyon.fr   */
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
	A = A;
	std::cout << B[2] << std::endl;
	try
	{
		A[4] = 7;
	}
	catch (std::exception &e)
	{
		std::cout << "I tried to go to the 7th element of a 4 size of my array A --> " << e.what() << std::endl; 
	}
	strs[0] = "coucou";
	std::cout << strs[0] << std::endl;
	const std::string &H = strs[0];
	std::cout << H << std::endl;
	Array<char> crash(0);
	try
	{
		crash[0] = 'u';
	}
	catch (std::exception &e)
	{
		std::cout << "I tried to allocate a value on an empty array --> " << e.what() << std::endl; 
	}

	const Array<std::string> &Constman = strs;
	const std::string	&constval = Constman[0];
	std::cout << "\n\n CONST DISPLAY IS POSSIBLE : \n\n" << constval << "\n\n";

    Array<char> crash2(2);
    crash2[0] = 'u';
    crash2 = crash;
    try
    {
        std::cout << crash[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
/*	Array<int> a(5);
	const Array<int> &c = a;

	const int &val = c[3];
	const int &b = a[3];
	int &c = a[3];
	(void) b;
	(void) c;
	c += 1;*/
}