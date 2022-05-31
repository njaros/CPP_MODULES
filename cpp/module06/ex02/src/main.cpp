/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 08:09:57 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 09:37:00 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/Base.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <exception>

Base	*generate( void )
{
	std::srand(time(NULL));
	switch (std::rand() % 3)
	{
		case (0) :
			std::cout << "A created" << std::endl;
			return (new(A));
		case (1) :
			std::cout << "B created" << std::endl;
			return (new(B));
		default :
			std::cout << "C created" << std::endl;
			return (new(C));			
	}
}

void	identify(Base *p)
{
	A*	ptrA;
	B*	ptrB;
	C*	ptrC;

	ptrA = dynamic_cast<A*>(p);
	if (ptrA)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	ptrB = dynamic_cast<B*>(p);
	if (ptrB)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	ptrC = dynamic_cast<C*>(p);
	if (ptrC)
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		A &tryA = dynamic_cast<A &>(p);
		(void) tryA;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{}
	try
	{
		B &tryB = dynamic_cast<B &>(p);
		(void) tryB;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{}
	try
	{
		C &tryC = dynamic_cast<C &>(p);
		(void) tryC;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{}
}

int	main(void)
{
	Base	*abc;
	abc = generate();
	Base	&abcRef = *abc;
	identify(abc);
	identify(abcRef);

	delete (abc);
}