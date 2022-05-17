/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:18:00 by njaros            #+#    #+#             */
/*   Updated: 2022/05/17 13:35:16 by njaros           ###   ########lyon.fr   */
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

//Je propose 2 solutions car le sujet peut être interprété de 2 façons différentes
void	Harl::complain( std::string level ) //solution 1 : ma préférée
{
	void	(Harl::*fPtr[4])( void );
	int		i;
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
	if (i < 4) // This if is here to avoid segFault.
	{
		(this->*fPtr[i])();
		return;
	}
	std::cout << "default : Writing or creating random absurd memes." << std::endl;
}

/*void	Harl::complain( std::string level ) //solution 2
{
	void	(Harl::*fPtr[4])( void );
	int		i;
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
	switch (i)
	{
		case 0 :
			(this->*fPtr[0])();
			break ;
		case 1 :
			(this->*fPtr[1])();
			break ;
		case 2 :
			(this->*fPtr[2])();
			break ;
		case 3 :
			(this->*fPtr[3])();
			break ;
		default :
			std::cout << "default : Writing or creating random absurd memes." << std::endl;
	}
}*/

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
