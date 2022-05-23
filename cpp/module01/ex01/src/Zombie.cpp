/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:40:30 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:40:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "Constructor message > an unamed zombie has been created" << std::endl;
}

Zombie::Zombie( std::string name ) : _zombieName(name)
{
	std::cout << "Constructor message > " << this->_zombieName << ": constructed." << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Destructor message > " << this->_zombieName << ": destroyed." << std::endl;
}

void	Zombie::setName ( std::string name )
{
	this->_zombieName = name;
	std::cout << "the name " << name << " has been set to a zombie." << std::endl;
}

void	Zombie::announce( void )	const
{
	std::cout << this->_zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
