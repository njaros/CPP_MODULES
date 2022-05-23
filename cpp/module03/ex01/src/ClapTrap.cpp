/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:43:33 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:45:20 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("unnamed"), _className("ClapTrap"), _healthPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor : An unnamed " << this->getClassName() << " has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _className("ClapTrap"), _healthPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor : A ClapTrap named " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &other ) : _name(other._name), _className(other._className), _healthPoints(other._healthPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor : A ClapTrap named " << this->_name << " has been copied" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor : The " << this->getClassName() << " " << this->_name << " has been deleted" << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->_energyPoints && this->_healthPoints)
	{
		std::cout << this->getClassName() << " " << this->getName() << " did " << this->_attackDamage << " damages to " << target << std::endl;
		this->_energyPoints -= 1;
	}
	else if (!this->_healthPoints)
		std::cout << this->getClassName() << " " << this->getName() << " couldn't attack " << target << " because he's too injured." << std::endl;
	else if (!this->_energyPoints)
		std::cout << this->getClassName() << " " << this->getName() << " couldn't attack " << target << " because he's too exhausted." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_healthPoints)
	{
		std::cout << "The poor " << this->getClassName() << " " << this->getName() << " is getting bullied..." << std::endl;
		return ;
	}
	this->_healthPoints -= amount;
	std::cout << this->getClassName() << " " << this->getName() << " took " << amount << " damages";
	if (this->_healthPoints <= 0)
	{
		this->_healthPoints = 0;
		std::cout << " and he's KO !" << std::endl;
	}
	else
		std::cout << ", he has " << this->_healthPoints << " HP left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints && this->_healthPoints)
	{
		std::cout << this->getClassName() << " " << this->getName() << " is repairing himself and gain " << amount << " health points.";
		this->_healthPoints += amount;
		this->_energyPoints -= 1;
		std::cout << " He has now " << this->_healthPoints << " hp." << std::endl;
	}
	else if (!this->_healthPoints)
		std::cout << this->getClassName() << " " << this->getName() << " is to injuried to be able to repair himself." << std::endl;
	else
		std::cout << this->getClassName() << " " << this->getName() << " couldn't repair himself because he's too exhausted." << std::endl;
}

void	ClapTrap::useEnergy(unsigned int amount)
{
	this->_energyPoints -= amount;
}

std::string	ClapTrap::getName( void )	const
{
	return (this->_name);
}

std::string	ClapTrap::getClassName( void )	const
{
	return (this->_className);
}

int	ClapTrap::getHp( void )	const
{
	return (this->_healthPoints);
}

int	ClapTrap::getEp( void )	const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAd( void )	const
{
	return (this->_attackDamage);
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
}

void	ClapTrap::setClassName( std::string name )
{
	this->_className = name;
}

void	ClapTrap::setHp( unsigned int value )
{
	this->_healthPoints = value;
}

void	ClapTrap::setEp( unsigned int value )
{
	this->_energyPoints = value;
}

void	ClapTrap::setAd( int value )
{
	this->_attackDamage = value;
}