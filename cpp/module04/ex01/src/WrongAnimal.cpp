/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:48:44 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:48:45 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _name("noName")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string name ) : _name(name)
{
	std::cout << "WrongAnimal constructor called : " << this->getName() << " is born." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const& other ) : _name(other.getName())
{
	std::cout << "WrongAnimal copy constructor called : " << this->getName() << " has been cloned" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructor called : " << this->getName() << " escaped." << std::endl;
}

std::string	WrongAnimal::getName( void )	const
{
	return (this->_name);
}

void	WrongAnimal::setName( std::string name )
{
	this->_name = name;
}

void	WrongAnimal::makeSound( void )	const
{
	std::cout << this->type << this->getName() << " : ?????WrongAnimal : UNDEFINED????" << std::endl;
}
