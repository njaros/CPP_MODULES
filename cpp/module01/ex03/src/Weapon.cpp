/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:11:08 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 11:32:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
	std::cout << this->_type << " created." << std::endl;
	return;
}

Weapon::~Weapon( void )
{
	return;
}

std::string &Weapon::getType( void )
{
	std::string &weaponREF = this->_type;
	return (weaponREF);	
}

void	Weapon::setType( std::string newType )
{
	this->_type = newType;
}
