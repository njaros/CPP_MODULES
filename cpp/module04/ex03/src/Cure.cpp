/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:53:18 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 15:35:24 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{}

Cure::Cure(Cure const &other) : AMateria(other)
{}

Cure::~Cure(void)
{}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}

AMateria	*Cure::clone( void )	const
{
	AMateria	*newMateria;

	newMateria = new Cure(*this);
	return (newMateria);
}
