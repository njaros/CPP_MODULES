/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MultiType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:48:32 by njaros            #+#    #+#             */
/*   Updated: 2022/05/30 16:45:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MultiType.hpp"

MultiType::MultiType( void ) :	_char(0), _int(0), _float(0), _double(0), _type(0), _errInt(0),
								_errFloat(0), _errDouble(0) ,_nan(0)
{}

MultiType::MultiType(std::string number, int type) :	_char(0), _int(0), _float(0), _double(0),
														_type(type), _errInt(0), _errFloat(0), _errDouble(0), _nan(0)
{
	if (!number.compare("NAN") || !number.compare("NANF"))
		this->_nan = 1;
	switch (type)
	{
		case (CHAR) :
			this->setChar(number);
			break ;
		case (INT) :
			this->setInt(number);
			break ;
		case (FLOAT) :
			this->setFloat(number);
			break ;
		default :
			this->setDouble(number);
	}
}

MultiType::MultiType(MultiType const &other) :	_char(other.getCharValue()), _int(other.getIntValue()),
												_float(other.getFloatValue()), _double(other.getDoubleValue()),
												_type(other.getType()), _errInt(other.getErrIntValue()),
												_errFloat(other.getErrFloatValue()), _errDouble(other.getErrDoubleValue()),
												_nan(other.getNanValue())
{}

MultiType::~MultiType( void )
{}

MultiType	&MultiType::operator=(MultiType const &other)
{
	this->_char = other.getCharValue();
	this->_int = other.getIntValue();
	this->_float = other.getFloatValue();
	this->_double = other.getDoubleValue();
	this->_errInt = other.getErrIntValue();
	this->_errFloat = other.getErrFloatValue();
	this->_errDouble = other.getDoubleValue();
	this->_type = other.getType();
	this->_nan = other.getNanValue();
	return (*this);
}

int	MultiType::getType( void )	const
{
	return (this->_type);
}

char	MultiType::getCharValue( void )	const
{
	return (this->_char);
}

int	MultiType::getIntValue( void )	const
{
	return (this->_int);
}

float	MultiType::getFloatValue( void )	const
{
	return (this->_float);
}

double	MultiType::getDoubleValue( void )	const
{
	return(this->_double);
}

bool	MultiType::getErrIntValue( void )	const
{
	return (this->_errInt);
}

bool	MultiType::getNanValue( void )	const
{
	return (this->_nan);
}

int	MultiType::getErrFloatValue( void )	const
{
	return (this->_errFloat);
}

int	MultiType::getErrDoubleValue( void )	const
{
	return (this->_errDouble);
}

void	MultiType::setChar(std::string number)
{
	this->_char = number.data()[0];
}

void	MultiType::setInt(std::string number)
{
	bool		sign = 0;
	int			idx = 0;
	std::string	toCompareMax;

	if (number.data()[idx] == '-' && ++idx)
		sign = 1;
	toCompareMax = number.substr(idx, number.size() - idx);
	if (toCompareMax.size() > 10)
	{
		this->_errInt = 1;
		return ;
	}
	toCompareMax.insert(0, 10 - toCompareMax.size(), '0');
	if (!sign && toCompareMax.compare(std::to_string(MAX_INT)) > 0)
	{
		this->_errInt = 1;
		return ;
	}
	if (sign && toCompareMax.compare(std::to_string(MIN_INT).substr(idx, std::to_string(MIN_INT).size() - idx)) > 0)
	{
		this->_errInt = 1;
		return ;
	}
	this->_int = std::stoi(number);
}

void	MultiType::setFloat(std::string number)
{
	std::string toCompareMax;
	int			idx = 0;
	bool		sign = 0;
	int			coma;
	int			comaMax;

	if (number.data()[0] == '-' && ++idx)
		sign = 1;
	toCompareMax = number.substr(idx, number.size() - idx);
	coma = number.find('.', 0);
	comaMax = std::to_string(MAX_FLOAT).find('.', 0);
	if (coma > comaMax)
	{
		if (!sign)
			this->_errFloat = 1;
		else
			this->_errFloat = 2;
		return ;
	}
	toCompareMax.insert(0, comaMax - coma, '0');
	toCompareMax.erase(toCompareMax.size() - 1, 1);
	if (toCompareMax.compare(std::to_string(MAX_FLOAT)) > 0)
	{
		if (!sign)
			this->_errFloat = 1;
		else
			this->_errFloat = 2;
		return ;
	}
	this->_float = std::stof(number);
}

void	MultiType::setDouble(std::string number)
{
	std::string toCompareMax;
	int			idx = 0;
	bool		sign = 0;
	int			coma;
	int			comaMax;

	if (number.data()[0] == '-' && ++idx)
		sign = 1;
	toCompareMax = number.substr(idx, number.size() - idx);
	coma = number.find('.', 0);
	comaMax = std::to_string(MAX_DOUBLE).find('.', 0);
	if (coma > comaMax)
	{
		if (!sign)
			this->_errDouble = 1;
		else
			this->_errDouble = 2;
		return ;
	}
	toCompareMax.insert(0, comaMax - coma, '0');
	toCompareMax.erase(toCompareMax.size() - 1, 1);
	if (toCompareMax.compare(std::to_string(MAX_DOUBLE)) > 0)
	{
		if (!sign)
			this->_errDouble = 1;
		else
			this->_errDouble = 2;
		return ;
	}
	this->_double = std::stod(number);
}

void	MultiType::displayChar( void )
{
	std::cout << "char: ";
	if (this->_nan)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (this->_errInt || this->_errFloat || this->_errDouble)
	{
		std::cout << "char overflow" << std::endl;
		return ;
	}
	switch (this->_type)
	{
		case (INT) :
			if (this->_int < MIN_CHAR || this->_int > MAX_CHAR)
			{
				std::cout << "char overflow" << std::endl;
				return ;
			}
			if (this->_int <= 31 || this->_int >= 127)
			{
				std::cout << "char " << this->_int << " isn't displayable" << std::endl;
				return ;
			}
			std::cout << (char)this->_int;
			break ;

		case (FLOAT) :
			if (this->_float < MIN_CHAR || this->_float > MAX_CHAR)
			{
				std::cout << "char overflow" << std::endl;
				return ;
			}
			if (this->_float <= 31 || this->_float >= 127)
			{
				std::cout << "char " << (int)this->_float << " isn't displayable" << std::endl;
				return ;
			}
			std::cout << (char)this->_float;
			break;
		
		case (DOUBLE) :
			if (this->_double < MIN_CHAR || this->_double > MAX_CHAR)
			{
				std::cout << "char overflow" << std::endl;
				return ;
			}
			if (this->_double <= 31 || this->_double >= 127)
			{
				std::cout << "char " << (int)this->_double << " isn't displayable." << std::endl;
				return ;
			}
			std::cout << (char)this->_double;
			break;

		default :
			std::cout << this->_char;
	}
	std::cout << std::endl;
}

void	MultiType::displayInt( void )
{
	std::cout << "int: ";
	if (this->_nan)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (this->_errInt || this->_errFloat || this->_errDouble)
	{
		std::cout << "int overflow" << std::endl;
		return ;
	}
	switch (this->_type)
	{
		case (CHAR) :
			std::cout << (int)this->_char;
			break ;
		
		case (FLOAT) :
			if (this->_float > MAX_INT || this->_float < MIN_INT)
			{
				std::cout << "int overflow" << std::endl;
				return ;
			}
			std::cout << (int)this->_float;
			break ;

		case (DOUBLE) :
			if (this->_double > MAX_INT || this->_double < MIN_INT)
			{
				std::cout << "int overflow." << std::endl;
				return ;
			}
			std::cout << (int)this->_double;
			break ;

		default :
			std::cout << this->_int;
	}
	std::cout << std::endl;
}

void	MultiType::displayFloat( void )
{
	std::cout << "float: ";
	if (this->_errFloat == 1 || this->_errDouble == 1)
	{
		std::cout << "inff" << std::endl;
		return ;
	}
	if (this->_errFloat == 2 || this->_errDouble == 2)
	{
		std::cout << "-inff" << std::endl;
		return ;
	}
	if (this->_errInt)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	switch (this->_type)
	{
		case (CHAR) : 
			std::cout << (float) this->_char << ".0";
			break ;
		
		case (INT) :
			std::cout << (float) this->_int << ".0";
			break ;

		case(DOUBLE) :
			std::cout << (float) this->_double;
			break ;
		
		default :
			std::cout << this->_float;
	}
	std::cout << "f" << std::endl; 
}

void	MultiType::displayDouble( void )
{
	std::cout << "double: ";
	if (this->_errFloat == 1 || this->_errDouble == 1)
	{
		std::cout << "inff" << std::endl;
		return ;
	}
	if (this->_errFloat == 2 || this->_errDouble == 2)
	{
		std::cout << "-inff" << std::endl;
		return ;
	}
	if (this->_errInt)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	switch (this->_type)
	{
		case (CHAR) : 
			std::cout << (float) this->_char << ".0";
			break ;
		
		case (INT) :
			std::cout << (float) this->_int << ".0";
			break ;

		case(FLOAT) :
			std::cout << (float) this->_float;
			break ;
		
		default :
			std::cout << this->_double;
	}
	std::cout << std::endl;
}
