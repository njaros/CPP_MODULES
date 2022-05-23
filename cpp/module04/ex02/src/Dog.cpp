/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:31 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 18:16:04 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal::Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called : ouaf" << std::endl;
}

Dog::Dog( std::string name ) : Animal::Animal( name )
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called, " << this->getName() << " is born : ouaf" << std::endl;
}

Dog::Dog( Dog const& other ) : Animal::Animal( other )
{
	this->_brain = new Brain();
	this->type = other.type;
	*(this->_brain) = *(other._brain);
	std::cout << "Dog copy constructor called, " << this->getName() << " has been cloned : ouaf" << std::endl;
}

Dog::~Dog( void )
{
	delete (this->_brain);
	std::cout << "Dog destructor called : " << this->type << " " << this->getName() << " escaped." << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	this->setName(other.getName());
	this->type = other.getType();
	*(this->_brain) = *(other._brain);
	return (*this);
}

void	Dog::makeSound( void )	const
{
	std::cout << this->type << " " << this->getName() << " says : as LJohnson said : ouaf" << std::endl;
}

Brain&	Dog::getBrain( void )	const
{
	return (*this->_brain);
}