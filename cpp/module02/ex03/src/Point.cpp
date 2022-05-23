/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:42:57 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:42:58 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point( void )
{
	return ;
}

Point::Point( float const x, float const y ) : _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::Point( const Point &p )
{
	*this = p;
}

Point::~Point( void )
{
	return ;
}

void	Point::setX( Fixed const x )
{
	this->_x = x;
}

void	Point::setX( float const x )
{
	this->_x = Fixed(x);
}

void	Point::setY( Fixed const y )
{
	this->_y = y;
}

void	Point::setY( float const y )
{
	this->_y = Fixed(y);
}

Fixed	Point::getX( void )	const
{
	return (this->_x);
}

Fixed	Point::getY( void )	const
{
	return (this->_y);
}

Point	&Point::operator=( Point const &p )
{
	this->setX(p.getX());
	this->setY(p.getY());
	return (*this);
}

bool	Point::halfPlan( Point const a, Point const b, Point const c )	const
{
	Fixed	coef_dir;
	Fixed	origine;

	if (a.getY() == b.getY())
	{
		if ((c.getY() >= a.getY()) && this->getY() >= a.getY())
			return (1);
		if ((c.getY() <= a.getY()) && this->getY() <= a.getY())
			return (1);
		return (0);
	}
	if (a.getX() == b.getX())
	{
		if ((c.getX() >= a.getX()) && this->getX() >= a.getX())
			return (1);
		if ((c.getX() <= a.getX()) && this->getX() <= a.getX())
			return (1);
		return (0);
	}
	coef_dir = ((a.getY() - b.getY()) / (a.getX() - b.getX()));
	origine = a.getY() - (coef_dir * a.getX());
	//std::cout << "a = " << coef_dir << " b = " << origine << std::endl;
	//std::cout << "y = " << coef_dir << "x + " << origine << std::endl;
	//std::cout << ((coef_dir * c.getX()) - c.getY() + origine) << std::endl;
	//std::cout << ((coef_dir * this->getX()) - this->getY() + origine) << std::endl;
	if ((Fixed(0) <= ((coef_dir * c.getX()) - c.getY() + origine)) &&
			Fixed(0) <= ((coef_dir * this->getX()) - this->getY() + origine))
		return (1);
	if ((Fixed(0) >= ((coef_dir * c.getX()) - c.getY() + origine)) &&
			Fixed(0) >= ((coef_dir * this->getX()) - this->getY() + origine))
		return (1);
	return (0);
}

std::ostream	&operator<<( std::ostream &o, Point const &p )
{
	o << "{" << p.getX() << "; " << p.getY() << "}";
	return (o);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (!(point.halfPlan(a, b, c)))
		return (0);
	if (!(point.halfPlan(a, c, b)))
		return (0);
	if (!(point.halfPlan(b, c, a)))
		return (0);
	return (1);
}

//a = (yA - yB) / (xA - xB)
//yA = xA * a + b
//b = yA - xA * a
//a * xA - yA + b = 0
//a * xA - yA + b < 0