/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:46:42 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:46:43 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	this->setName("unnamed");
	this->setClassName("ScavTrap");
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
	std::cout << "ScavTrap default constructor : An unnamed ScavTrap has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string name )
{
	this->setName(name);
	this->setClassName("ScavTrap");
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
	std::cout << "ScavTrap constructor : A ScavTrap named " << this->getName() << " has been created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &other ) : ClapTrap()
{
	this->setName(other.getName());
	this->setClassName(other.getClassName());
	this->setHp(other.getHp());
	this->setEp(other.getEp());
	this->setAd(other.getAd());
	std::cout << "ScavTrap copy constructor : A ScavTrap named " << this->getName() << " has been copied" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor from  " << this->getClassName() << " " << this->getName() << " : called" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << this->getClassName() << " " << this->getName() << " has entering Gate Keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEp() && this->getHp())
	{
		std::cout << this->getClassName() << " " << this->getName() << " did " << this->getAd() << " damages while trying to hugging to " << target << std::endl;
		this->useEnergy(1);
	}
	else if (!this->getHp())
		std::cout << this->getClassName() << " " << this->getName() << " couldn't hug " << target << " because he's too injured." << std::endl;
	else if (!this->getEp())
		std::cout << this->getClassName() << " " << this->getName() << " couldn't hug " << target << " because he's too exhausted." << std::endl;
}
