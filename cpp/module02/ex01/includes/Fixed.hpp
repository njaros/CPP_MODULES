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

		Fixed( void );
		Fixed( const Fixed &n );
		Fixed( int const wut );
		Fixed( float const wut );
		~Fixed( void );
		float	toFloat( void )	const;
		int		toInt( void )	const;
		int		getRawBits( void )	const;
		void	setRawBits( int const raw );
		Fixed	&operator=( Fixed const &n );

	private :

		int					_n;
		static int const	_fixedPoint = 8;

};

		std::ostream	&operator<<( std::ostream &o, Fixed const &f );

#endif