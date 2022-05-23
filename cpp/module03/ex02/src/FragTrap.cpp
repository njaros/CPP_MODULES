/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:46:31 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:46:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap( void )
{
	this->setName("unnamed");
	this->setClassName("FragTrap");
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
	std::cout << "FragTrap default constructor : An unnamed FragTrap has been created AND IS READY TO BREAK MOUTHS" << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	this->setName(name);
	this->setClassName("FragTrap");
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
	std::cout << "FragTrap constructor : A FragTrap named " << this->getName() << " has been created AND IS READY TO BREAK MOUTHS" << std::endl;
}

FragTrap::FragTrap( FragTrap const &other ) : ClapTrap()
{
	this->setName(other.getName());
	this->setClassName(other.getClassName());
	this->setHp(other.getHp());
	this->setEp(other.getEp());
	this->setAd(other.getAd());
	std::cout << "FragTrap copy constructor : A FragTrap named " << this->getName() << " has been copied AND IS READY TO BREAK MOUTHS" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor from  " << this->getClassName() << " " << this->getName() << " : called. Mouths are safe now." << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << this->getClassName() << " " << this->getName() << " : HIGH FIVES DUDES !!" << std::endl;
}
