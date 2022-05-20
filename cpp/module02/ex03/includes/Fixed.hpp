/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:09:18 by njaros            #+#    #+#             */
/*   Updated: 2022/05/19 17:54:48 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	public :

		// Les constructeurs

		Fixed( void );
		Fixed( const Fixed &n );
		Fixed( int const n );
		Fixed( float const f );
		
		// Le destructeur

		~Fixed( void );

		// Les opérateurs de surcharge arithmétiques

		Fixed	&operator=( Fixed const &n );
		Fixed	operator+( Fixed const &val );
		Fixed	operator-( Fixed const &val );
		Fixed	operator*( Fixed const &val );
		Fixed	operator/( Fixed const &val );

		// Les opérateurs de surcharge de comparaison

		bool	operator>( Fixed const &rVal );
		bool	operator<( Fixed const &rVal );
		bool	operator>=( Fixed const &rVal );
		bool	operator<=( Fixed const &rVal );
		bool	operator==( Fixed const &rVal );
		bool	operator!=( Fixed const &rVal );

		// Les opérateurs de surcharge de post et pré incrémantation et décrémentation

		Fixed	operator++( void );
		Fixed	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		// Les opérateurs de surcharges min et max

		static Fixed		&max( Fixed &lVal, Fixed &rVal );
		static Fixed const	&max( Fixed const &lVal, Fixed const &rVal );
		static Fixed		&min( Fixed &lVal, Fixed &rVal );
		static Fixed const	&min( Fixed const &lVal, Fixed const &rVal );
		
		// Geter, seter, autres...

		float	toFloat( void )	const;
		int		toInt( void )	const;
		int		getRawBits( void )	const;
		void	setRawBits( int const raw );

	private :

		int					_n;
		static int const	_fixedPoint = 8;

};

	std::ostream	&operator<<( std::ostream &o, Fixed const &f );

#endif