/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:18:00 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 19:27:19 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	this->ptrDebug = &this->debug;
	this->ptrInfo = &this->info;
	this->ptrWarning = &this->warning;
	this->ptrError = &this->error;
	this->ptrs[0] = this->ptrDebug;
	this->ptrs[1] = this->ptrInfo;
	this->ptrs[2] = this->ptrWarning;
	this->ptrs[3] = this->ptrError;
	return;
}

Harl::~Harl( void )
{
	return;
}

void	Harl::complain( std::string level )
{
	this->ptrs[atoi(level)];
}

void	Harl::debug( void )
{
	std::cout << "debug" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "info" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "warning" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "error" << std::endl;
}