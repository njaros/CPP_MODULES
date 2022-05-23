/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:48 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:42:49 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public :

		Point( void );
		Point( float const x, float const y );
		Point( const Point &p );
		~Point( void );

		void		setX( Fixed const x );
		void		setX( float const x );
		void		setY( Fixed const y );
		void		setY( float const y );
		Fixed		getX( void )	const;
		Fixed		getY( void )	const;

		Point		&operator=( Point const &p );
		bool		halfPlan( Point const a, Point const b, Point const c )	const;

	private :

		Fixed	_x;
		Fixed	_y;

};

	bool	bsp( Point const a, Point const b, Point const c, Point const point);
	std::ostream	&operator<<( std::ostream &o, Point const &p );

#endif
