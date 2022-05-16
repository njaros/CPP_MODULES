/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:21:53 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 11:32:32 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	std::cout << this->_name << " created." << std::endl;
	this->_weapon = NULL;
	return;
}

HumanB::~HumanB( void )
{
	std::cout << this->_name << " destroyed." << std::endl;
	return;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void )	const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
