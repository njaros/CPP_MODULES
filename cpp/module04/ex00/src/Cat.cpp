/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:28 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 17:45:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal::Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called : MEOOOOWWW?" << std::endl;
}

Cat::Cat( std::string name ) : Animal::Animal( name )
{
	this->type = "Cat";
	std::cout << "Cat constructor called, " << this->getName() << " is born : MEOOOOWWW?" << std::endl;
}

Cat::Cat( Cat const& other ) : Animal::Animal( other )
{
	this->type = other.type;
	std::cout << "Cat copy constructor called, " << this->getName() << " has been cloned : MEOOOOWWW?" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called : " << this->type << " " << this->getName() << " escaped." << std::endl;
}

void	Cat::makeSound( void )	const
{
	std::cout << this->type << " " << this->getName() << " says : MEOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOWWWWW" << std::endl;
}