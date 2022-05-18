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
	return (this->_n);
}

void	Fixed::setRawBits( int const raw )
{
	this->_n = raw;
}

Fixed::Fixed( int const n ) : _n(n << 8)
{
	if (n < 0)
		_n |= 0x80000000;
	std::cout << "Int constructor called" << std::endl;
}

//Mantisse and exposant for float definition in 
//https://fr.wikipedia.org/wiki/IEEE_754
//I had to read and anderstand this to do the followings

Fixed::Fixed( float const f )
{
	//I build my rawInt step by step to not get lost
	
	bool	sign;
	int		exposant;
	int		mantisse;	
	
	//My first step is to know float mantissem exposant and sign

	sign = 0;
	if (f < 0)
		sign += 1;			//Sign stored
	exposant = f;
	exposant &= ~0x80000000;
	exposant >>= 23;
	exposant -= 127;		//Exposant stored
	mantisse = f;
	mantisse <<= 8;
	mantisse |= 0x80000000; //I put the strongest bit, float don't need it
							//so I need to put him by hand
	mantisse >>= 23;		//Mantisse stored
	this->_n = mantisse << exposant;
	if (sign)
		this->_n |= 0x80000000;
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat( void )	const
{
	int		to_build;	//I'll build my float step by step
						//in order to explain more easely
	float	*to_return;
	int		mantisse;
	int		strongestBit = 0x40000000;

	to_return = (float *)&to_build;
	mantisse = this->_n;
	to_build = 0.0;
	to_build |= 151 << 23;	//Fixed number always has the fixed point to 8
							//So the float exposant is 127 + (32 - 8) << 23
	if (mantisse < 0)
		to_build |= 0x80000000;	//Set up of the sign bit
	mantisse &= ~0x80000000;	//To build the mantisse, I need to delete bit sign
	while (!(mantisse & strongestBit))
		strongestBit >>= 1;
	mantisse ^= strongestBit;	//Here I put to 0 the strongest bit of my raw number
	while (!(mantisse & 0x80000000))
		mantisse <<= 1;
	mantisse >>= 9;			//My mantisse is now built
	to_build |= mantisse;
	return (*to_return);
}

int	Fixed::toInt( void )	const
{
	int	round;

	round = 0;
	if (this->_n & 0x80)
		round++;
	return ((this->_n >> 8) + round);
}

std::ostream	&operator<<( std::ostream &o, Fixed const &f )
{
	int		to_print;
	int		big;	//the part which is > 1 (after the 8th bit (not included))
	int		small;	//the part which is < 0 (before the 8th bit (included))
	bool	sign;

	to_print = f.getRawBits();
	sign = 0;
	if (to_print < 0)
		sign += 1;
	big = to_print;
	if (sign)
		big &= ~0x80000000;
	big >>= 8;
	if (sign)
		big &= 0x80000000;
	small = to_print &= 0x000000ff;
	o << big;
	if (small)
		o << "." << small;
	return (o);
}
