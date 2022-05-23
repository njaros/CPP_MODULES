/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:25 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 17:30:00 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal( void ) : _name("noName")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string name ) : _name(name)
{
	std::cout << "Animal constructor called : " << this->getName() << " is born." << std::endl;
}

Animal::Animal( Animal const& other ) : _name(other.getName())
{
	std::cout << "Animal copy constructor called : " << this->getName() << " has been cloned" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called : " << this->getName() << " escaped." << std::endl;
}

Animal&	Animal::operator=( const Animal& other )
{
	this->setName(other.getName());
	this->type = other.type;
	return (*this);
}

std::string	Animal::getName( void )	const
{
	return (this->_name);
}

std::string	Animal::getType( void )	const
{
	return (this->type);
}

void	Animal::setName( std::string name )
{
	this->_name = name;
}

void	Animal::makeSound( void )	const
{
	std::cout << this->type << this->getName() << " : ?????UNDEFINED????" << std::endl;
}
