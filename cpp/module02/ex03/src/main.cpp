/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:03:24 by njaros            #+#    #+#             */
/*   Updated: 2022/05/19 18:43:16 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include <stdlib.h>

int main( int ac, char **av )
{
	Point 		a(-2, 2);
	Point 		b(3.1, 10.0);
	Point 		c(10.0, 0.0);
	Point		p;
	float		pX;
	float		pY;

	if (ac != 3)
		return (1);
	pX = std::atof(av[1]);
	pY = std::atof(av[2]);
	p = Point(pX, pY);
	if (bsp(a, b, c, p))
		std::cout << "le point " << p << " est bien contenu dans le triangle ";
	else
		std::cout << "le point " << p << " n'est pas contenu dans le triangle ";
	std::cout << "de sommets :" << a << ", " << b << " et " << c << std::endl;
	return (0);
}