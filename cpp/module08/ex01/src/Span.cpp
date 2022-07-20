/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:06:56 by njaros            #+#    #+#             */
/*   Updated: 2022/06/28 09:39:13 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : _size(0)
{}

Span::Span(unsigned int size) : _size(size)
{}

Span::Span( Span const &other )
{
	*this = other;
}

Span::~Span()
{}

Span	&Span::operator=( Span const &other )
{
	this->_size = other.getSize();
	this->_vector = other.getVector();
	return (*this);
}

unsigned int	Span::getSize()	const
{
	return (this->_size);
}

std::vector<int>	Span::getVector()	const
{
	return (this->_vector);
}

void	Span::addNumber(int n)
{
	if (this->_vector.size() == this->_size)
		throw ("Vector is full.");
	this->_vector.push_back(n);
}

long int	Span::shortestSpan()	const
{
	std::vector<long int> minDistValue;
	std::vector<long int> diffList;
	std::vector<const int>::iterator	it;
	std::vector<const int>::iterator	diff;

	if (this->_vector.size() < 2)
		throw ("Vector must at least contain 2 numbers.");
	it = this->_vector.begin();
	while (it != this->_vector.end())
	{
		diff = this->_vector.begin();
		while (diff != this->_vector.end())
		{
			if (diff != it)
				diffList.push_back(std::abs(static_cast<long int> (*it) - static_cast<long int> (*diff)));
			diff++;
		}
		minDistValue.push_back(*std::min_element(diffList.begin(), diffList.end()));
		diffList.clear();
		it++;
	}
	return (*std::min_element(minDistValue.begin(), minDistValue.end()));
}

long int	Span::longestSpan()	const
{
	if (this->_vector.size() < 2)
		throw ("Vector must at least contain 2 numbers.");
	return (static_cast<long int> (*std::max_element(this->_vector.begin(), this->_vector.end())) - static_cast<long int> (*std::min_element(this->_vector.begin(), this->_vector.end())));
}