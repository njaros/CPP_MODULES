/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MultiType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:48:32 by njaros            #+#    #+#             */
/*   Updated: 2022/05/27 17:04:02 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MultiType.hpp"

MultiType::MultiType( void )
{}

MultiType::MultiType(char c) : _type(CHAR), _char(c)
{
	/*this->charToInt();
	this->charToFloat();
	this->charToDouble();*/
}

MultiType::MultiType(int i) : _type(INT), _int(i)
{
/*	this->intToChar();
	this->intToFloat();
	this->intToDouble();*/
}

MultiType::MultiType(float f) : _type(FLOAT), _float(f)
{
	/*this->floatToChar();
	this->floatToInt();
	this->floatToDouble();*/
}

MultiType::MultiType(double d) : _type(DOUBLE), _double(d)
{
	/*this->doubleToChar();
	this->doubleToInt();
	this->doubleToFloat();*/
}

MultiType::MultiType(MultiType const &other) : _type(other.getType()), _char(other.getCharValue()), _int(other.getIntValue()),
												_float(other.getFloatValue()), _double(other.getDoubleValue())
{}

MultiType::~MultiType( void )
{}

MultiType	&MultiType::operator=(MultiType const &other)
{
	this->_char = other._char;
	this->_int = other._int;
	this->_float = other._float;
	this->_double = other._double;
	return (*this);
}

void	MultiType::displayChar( void )
{
	if (this->_type == CHAR)
		std::cout << "char: " << this->getCharValue() << std::endl;
	
}

void	MultiType::displayInt( void )
{

}

void	MultiType::displayFloat( void )
{

}

void	MultiType::displayDouble( void )
{
	
}