/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:59:55 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 15:35:06 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{}

Ice::Ice(Ice const &other) : AMateria(other)
{}

Ice::~Ice(void)
{}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria	*Ice::clone( void )	const
{
	AMateria	*newMateria;

	newMateria = new Ice(*this);
	return (newMateria);
}
