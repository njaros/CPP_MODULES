/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:43:45 by njaros            #+#    #+#             */
/*   Updated: 2022/05/19 18:40:38 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0)
{
	return;
}

Fixed::~Fixed( void )
{
	return;
}

Fixed	&Fixed::operator=( Fixed const &n )
{
	this->setRawBits(n.getRawBits());
	return *this;
}

Fixed::Fixed( const Fixed &n )
{
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
}

//Mantisse and exposant for float definition in 
//https://fr.wikipedia.org/wiki/IEEE_754
//I had to read and anderstand this to do the followings

Fixed::Fixed( float const f )
{
	//I build my rawInt step by step to not get lost
	float	f_mantisse;
	float	f_exposant;
	bool	sign;
	int		*exposant;
	int		*mantisse;
	
	//My first step is to know float mantisse, exposant and sign

	if (!f)
	{
		this->_n = 0;
		return ;
	}
	f_exposant = f;					//I copy because f is const.
	f_mantisse = f;					//New copy because f_exposant will be unusable after his traitment
	sign = 0;
	if (f < 0)
		sign += 1;					//Sign stored
	exposant = (int *) &f_exposant;	//No choice to do this trick to manipulate bits in a float.
	*exposant &= ~0x80000000;
		*exposant >>= 23;
	*exposant -= 127;				//Exposant stored
	mantisse = (int *) &f_mantisse;
	*mantisse &= 0x7fffff;			//I put to 0 the non-mantisse bits.
	*mantisse |= 0x800000;			//I put the strongest bit, float don't need it
									//so I need to put it by hand.
									//Mantisse stored.
	this->_n = *mantisse >> (23 - (*exposant + this->_fixedPoint));
	f_mantisse = f;					//I look if the next precision bit in the float I couldn't treat is 1 or 0.
									//If it's 1, I round.
	if (*mantisse & (1 << (22 - (this->_fixedPoint + *exposant))))
		this->_n += 1;
	if (sign)						//I use the "2's complement" to sign my number; (= invert all bit and do +1)
	{
		this->_n = ~this->_n;
		this->_n += 1;
	}
}

float	Fixed::toFloat( void )	const
{
	int		to_build;	//I'll build my float step by step
						//in order to explain more easely
	float	*to_return;
	bool	sign;
	int		mantisse;
	int		exposant;
	int		strongestBit = 0x40000000;

	if (!this->_n)
		return (0.0);
	sign = 0;
	exposant = 22;
	to_return = (float *)&to_build;	//I only can build bit per bit an integer, so I use this trick to return a float
	mantisse = this->_n;
	to_build = 0.0;
	if (mantisse < 0)
	{
		sign += 1;
		mantisse -= 1;
		mantisse = ~mantisse;
	}
	while (!(mantisse & strongestBit))
	{
		strongestBit >>= 1;
		exposant -= 1;
	}
	to_build |= (127 + exposant) << 23;	//I build here the part "exposant" of the float by counting all non decimal bits
	mantisse ^= strongestBit;			//Here I put to 0 the strongest bit of my raw number (following float definition)
										//My mantisse is now built
	while (strongestBit != 0x800000)
	{
		if (strongestBit > 0x800000)
		{
			strongestBit >>= 1;
			mantisse >>= 1;
		}
		else
		{
			strongestBit <<= 1;
			mantisse <<= 1;
		}
	}
	to_build |= mantisse;
	if (sign)
		to_build |= 0x80000000;
	return (*to_return);
}

int	Fixed::toInt( void )	const
{
	bool	round;
	bool	sign;
	int		to_build;

	sign = 0;
	round = 0;
	if (this->_n & 0x80)
		round += 1;
	if (this->_n < 0)
		sign += 1;
	to_build = this->_n;
	to_build >>= 8;
	to_build += round;
	if (!to_build)
		return (0);
	if (sign)
		to_build |= 0x80000000;
	return (to_build);
}

Fixed	Fixed::operator+( Fixed const &val )
{
	float	result;

	result = this->toFloat() + val.toFloat();
	return (Fixed(result));
}

Fixed	Fixed::operator-( Fixed const &val )
{
	float	result;

	result = this->toFloat() - val.toFloat();
	return (Fixed(result));
}

Fixed	Fixed::operator*( Fixed const &val )
{
	float	result;

	result = this->toFloat() * val.toFloat();
	return (Fixed(result));
}

Fixed	Fixed::operator/( Fixed const &val )
{
	float	result;

	result = this->toFloat() / val.toFloat();
	return (Fixed(result));
}

bool	Fixed::operator>( Fixed const &rVal )
{
	return (this->getRawBits() > rVal.getRawBits());
}

bool	Fixed::operator<=( Fixed const &rVal )
{
	return (!(*this > rVal));
}

bool	Fixed::operator<( Fixed const &rVal )
{
	return (this->getRawBits() < rVal.getRawBits());
}

bool	Fixed::operator>=( Fixed const &rVal )
{
	return (!(*this < rVal));
}

bool	Fixed::operator==( Fixed const &rVal )
{
	return (this->getRawBits() == rVal.getRawBits());
}

bool	Fixed::operator!=( Fixed const &rVal )
{
	return (!(*this == rVal));
}

Fixed	Fixed::operator++( void )
{
	this->_n += 1;
	return (*this);
}

Fixed	Fixed::operator--( void )
{
	this->_n -= 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	temp( *this );
	this->_n += 1;
	return (temp);
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp( *this );
	this->_n -= 1;
	return (temp);
}

Fixed	&Fixed::max( Fixed &lVal, Fixed &rVal )
{
	if (lVal > rVal)
		return (lVal);
	return (rVal);
}

Fixed const	&Fixed::max( Fixed const &lVal, Fixed const &rVal )
{
	if (lVal.getRawBits() > rVal.getRawBits())
		return (lVal);
	return (rVal);
}

Fixed	&Fixed::min( Fixed &lVal, Fixed &rVal )
{
	if (lVal < rVal)
		return (lVal);
	return (rVal);
}
Fixed const	&Fixed::min( Fixed const &lVal, Fixed const &rVal )
{
	if (lVal.getRawBits() < rVal.getRawBits())
		return (lVal);
	return (rVal);
}

std::ostream	&operator<<( std::ostream &o, Fixed const &f )
{
	o << f.toFloat();
	return (o);
}
