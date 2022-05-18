/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:09:18 by njaros            #+#    #+#             */
/*   Updated: 2022/05/17 16:26:10 by njaros           ###   ########lyon.fr   */
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
		Fixed( int const wut );
		Fixed( float const wut );
		
		// Le destructeur

		~Fixed( void );

		// La surcharge d'operateur

		Fixed	&operator=( Fixed const &n );
		
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