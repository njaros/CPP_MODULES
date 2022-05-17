/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:18:00 by njaros            #+#    #+#             */
/*   Updated: 2022/05/17 11:27:01 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	return;
}

Harl::~Harl( void )
{
	return;
}

void	Harl::complain( std::string level )
{
	void	(Harl::*fPtr[4])( void );
	int	i;
	std::string	lvl[] = {
		"ERROR",
		"WARNING",
		"INFO",
		"DEBUG"
	};

	fPtr[0] = (&Harl::error);
	fPtr[1] = (&Harl::warning);
	fPtr[2] = (&Harl::info);
	fPtr[3] = (&Harl::debug);
	i = 0;
	while(i < 4 && lvl[i].compare(level))
		i++;
	// Je refuse d'utiliser switch, c'est une énorme incohérence du sujet : on nous apprend les pointeurs sur fonction
	// pour nous apprendre à les manipuler, et le sujet nous demande d'utiliser switch qui EST une foret de if/else par
	// définition et qui est un outil qui est utile que si on a pas de pointeurs sur fonction. Je trouve ça honteux...
	if (i < 4)
	{
		while (i >= 0)
		{
			(this->*fPtr[i])();
			i--;
		}
		return;
	}
	std::cout << "default : Writing or creating random absurd memes." << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "debug : In World_Random, We love memes and absurd things, we love baguettes and croissants too." << std::endl;
}

void	Harl::info( void )
{
	std::cout << "info : World_Random channel is english only, or we'll have some arguments." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "warning : I said ENGLISH ONLY, or I'll have to use some dangerous stuffs, you REALLY don't want that" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "error : ASFOIAHFKAKL AFAWFPAWJFp J OPAWF ANWF BGO BWio IW nIOb LAg a BABWO IAGI ABIGO BIOWBG oiwbg OBGWo BWFO AH IOb BFWo bOAWbf OAf bAb ioBW OFB OAfb OBG OBG OGB GB OWG" << std::endl;
}
