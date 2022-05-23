/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:45 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:47:47 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal::WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called : FFFSHHHHHHHHH?" << std::endl;
}

WrongCat::WrongCat( std::string name ) : WrongAnimal::WrongAnimal( name )
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called, " << this->getName() << " is born : FFFSHHHHHHHHH?" << std::endl;
}

WrongCat::WrongCat( WrongCat const& other ) : WrongAnimal::WrongAnimal( other )
{
	this->type = other.type;
	std::cout << "WrongCat copy constructor called, " << this->getName() << " has been cloned : FFFSHHHHHHHHH?" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called : " << this->type << " " << this->getName() << " escaped." << std::endl;
}

void	WrongCat::makeSound( void )	const
{
	std::cout << this->type << " " << this->getName() << " says : FFFFFFFFFFFFFFFFFFFFFFFFSHHHHH" << std::endl;
}