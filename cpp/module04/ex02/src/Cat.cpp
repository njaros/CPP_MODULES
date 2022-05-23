/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:28 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 18:10:22 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal::Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called : MEOOOOWWW?" << std::endl;
}

Cat::Cat( std::string name ) : Animal::Animal( name )
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called, " << this->getName() << " is born : MEOOOOWWW?" << std::endl;
}

Cat::Cat( Cat const& other ) : Animal::Animal( other )
{
	this->_brain = new Brain();
	this->type = other.type;
	*(this->_brain) = *(other._brain);
	std::cout << "Cat copy constructor called, " << this->getName() << " has been cloned : MEOOOOWWW?" << std::endl;
}

Cat::~Cat( void )
{
	delete (this->_brain);
	std::cout << "Cat destructor called : " << this->type << " " << this->getName() << " escaped." << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	this->setName(other.getName());
	this->type = other.getType();
	*(this->_brain) = *(other._brain);
	return (*this);
}

void	Cat::makeSound( void )	const
{
	std::cout << this->type << " " << this->getName() << " says : MEOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOWWWWW" << std::endl;
}

Brain&	Cat::getBrain( void )	const
{
	return (*this->_brain);
}