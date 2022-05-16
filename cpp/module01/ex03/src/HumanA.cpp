/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:14:28 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 11:32:13 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon)
{
	std::cout << this->_name << " created." << std::endl;
	return;
}

HumanA::~HumanA ( void )
{
	std::cout << this->_name << " destroyed." << std::endl;
	return;
}

void	HumanA::attack( void )	const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
