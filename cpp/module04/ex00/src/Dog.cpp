/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:31 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 17:45:37 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal::Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called : ouaf" << std::endl;
}

Dog::Dog( std::string name ) : Animal::Animal( name )
{
	this->type = "Dog";
	std::cout << "Dog constructor called, " << this->getName() << " is born : ouaf" << std::endl;
}

Dog::Dog( Dog const& other ) : Animal::Animal( other )
{
	this->type = other.type;
	std::cout << "Dog copy constructor called, " << this->getName() << " has been cloned : ouaf" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called : " << this->type << " " << this->getName() << " escaped." << std::endl;
}

void	Dog::makeSound( void )	const
{
	std::cout << this->type << " " << this->getName() << " says : as LJohnson said : ouaf" << std::endl;
}