/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:20:25 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 15:45:36 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character( void ) : _name("noName")
{
	int	i;

	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
}

Character::Character( std::string name ) : _name(name)
{
	int	i;

	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
}

Character::Character(Character const &other) : _name(other.getName())
{
	int	i;

	i = -1;
	while (++i < 4)
		_inventory[i] = other._inventory[i]->clone();
}

Character::~Character(void)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

Character	&Character::operator=( Character const &other )
{
	int	i;

	this->_name = other.getName();
	i = -1;
	while (++i < 4)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

void	Character::equip(AMateria *m)
{
	int	i;

	i = -1;
	while (++i < 4 && this->_inventory[i]);
	if (i < 4)
		_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
		delete (this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
}

std::string const	&Character::getName(void)	const
{
	return (this->_name);
}
