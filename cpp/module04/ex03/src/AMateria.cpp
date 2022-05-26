/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:28:24 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 15:36:05 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

// Unusable fonctions/constructors, existing to repect the Coplien form
AMateria::AMateria(void)
{
	std::cout << "Si ce message pop, j'ai KO, en plus la langue française est interdite par la norme std::endl";
}

AMateria& AMateria::operator=( AMateria const &other )
{
	//unusable because I choose to const the type.
	(void) other;
	return (*this);
}

// Usable fonctions/constructors/destructor
AMateria::AMateria(std::string const &type) : _type(type)
{}

AMateria::AMateria(AMateria const &other) : _type(other.getType())
{}

AMateria::~AMateria( void )
{}

std::string const	&AMateria::getType(void)	const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "A non existing materia is used to " << target.getName() << std::endl;
}
