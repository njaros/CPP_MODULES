/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:48:25 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:48:26 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain default constructor called : 100 strings memory available" << std::endl;
}

Brain::Brain( Brain const& other )
{
	this->_ideas = other._ideas;
	std::cout << "Brain copy constructor called : 100 strings memory available" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor : I decided to escape" << std::endl;
}

Brain	&Brain::operator=( Brain const& other )
{
	int	i;

	i = -1;
	while (++i < 100)
		this->_ideas[i] = other._ideas[i];
	return  (*this);
}

void	Brain::setIdea( unsigned int i, std::string idea )
{
	if (i >= 100)
		std::cout << "This brain is not that big !" << std::endl;
	else
	{
		this->_ideas[i] = idea;
		std::cout << "The idea has been stored in the brain" << std::endl;
	}
}

std::string	Brain::getIdea( unsigned int i )	const
{
	if (i >= 100)
		return ("This brain is not that big !")
	return (this->_ideas[i]);
}