/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:24:00 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 16:00:01 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	int	i;

	i = -1;
	while (++i < 4)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = other;
}

MateriaSource::~MateriaSource( void )
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = -1;
	while (++i < 4 && this->_inventory[i]);
	if (i < 4)
		this->_inventory[i] = m->clone();
	delete (m);
	// I could just do "this->_inventory[i] = m" but the subject said to copy the Materia and keep it in memory.
	// is "it" m ? or "it" is the copy of m ? The subject if really confused, but I'm able to code all the possible meanings
	// Here I decided to clone (because using copy constructor or an abstact class is impossible), keep the clone in memory
	// Then delete(m) to avoid memory leaks with the main I have to test
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (this->_inventory[i] && !this->_inventory[i]->getType().compare(type))
			return (this->_inventory[i]->clone());
	}
	return (0);
}
