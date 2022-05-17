/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:45 by njaros            #+#    #+#             */
/*   Updated: 2022/05/17 16:28:37 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( Fixed const &n )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(n.getRawBits());
	return *this;
}

Fixed::Fixed( const Fixed &n )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = n;
}

int	Fixed::getRawBits( void )	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void	Fixed::setRawBits( int const raw )
{
	this->_n = raw;
}

Fixed::Fixed( int const wut )
{
	
}

Fixed::Fixed( float const wut )
{

}

float	Fixed::toFloat( void )	const
{

}

int	Fixed::toInt( void )	const
{
	
}

std::ostream	&operator<<( std::ostream &o, Fixed const &f )
{
	
}
