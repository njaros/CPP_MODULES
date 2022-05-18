/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:14:28 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 17:20:56 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA ( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA ( void )
{
	return;
}

void	HumanA::attack( void )	const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
