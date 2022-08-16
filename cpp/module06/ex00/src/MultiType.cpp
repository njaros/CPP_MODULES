/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MultiType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:48:32 by njaros            #+#    #+#             */
/*   Updated: 2022/08/16 15:58:00 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MultiType.hpp"

MultiType::MultiType( void ) :	_char(0), _int(0), _float(0), _double(0), _type(0), _errInt(0),
								_errFloat(0), _errDouble(0) ,_nan(0) , _displayComaZero(0)
{}

MultiType::MultiType(std::string number, int type) :	_char(0), _int(0), _float(0), _double(0),
														_type(type), _errInt(0), _errFloat(0), _errDouble(0), _nan(0),
														_displayComaZero(0)
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
												_nan(other.getNanValue()), _displayComaZero(other.getDisplayComaZero())
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
	this->_displayComaZero = other.getDisplayComaZero();
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

bool	MultiType::getDisplayComaZero( void )	const
{
	return (this->_displayComaZero);
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
	this->_displayComaZero = 1;
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
	if (!sign && toCompareMax.compare(MAX_INT_STR) > 0)
	{
		this->_errInt = 1;
		return ;
	}
	if (sign && toCompareMax.compare(std::string(MIN_INT_STR).substr(idx, std::string(MIN_INT_STR).size() - idx)) > 0)
	{
		this->_errInt = 1;
		return ;
	}
	this->_int = std::atoi(number.data());
	if (this->_int < 1000000 && this->_int > -1000000)
		this->_displayComaZero = 1;
}

void	MultiType::setFloat(std::string number)
{
	std::string toCompareMax;
	int			sign = 0;
	int			coma;
	int			comaMax;

	if (number.data()[0] == '-')
		sign = 1;
	toCompareMax = number.substr(sign, number.size() - sign);
	coma = toCompareMax.find('.', 0);
	comaMax = std::string(MAX_FLOAT).find('.', 0);
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
	if (toCompareMax.compare(MAX_FLOAT) > 0)
	{
		if (!sign)
			this->_errFloat = 1;
		else
			this->_errFloat = 2;
		return ;
	}
	this->_float = std::atof(number.data());
	if (this->_float < 1000000 && this->_float > -1000000)
	{
		coma += 1 + sign;
		while (number.data()[coma] == '0')
			coma++;
		if (number.data()[coma] == 'F')
			this->_displayComaZero = 1;
	}
}

void	MultiType::setDouble(std::string number)
{
	std::string toCompareMax;
	int			sign = 0;
	int			coma;
	int			comaMax;

	if (number.data()[0] == '-')
		sign = 1;
	toCompareMax = number.substr(sign, number.size() - sign);
	coma = toCompareMax.find('.', 0);
	comaMax = std::string(MAX_DOUBLE).find('.', 0);
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
	if (toCompareMax.compare(MAX_DOUBLE) > 0)
	{
		if (!sign)
			this->_errDouble = 1;
		else
			this->_errDouble = 2;
		return ;
	}
	this->_double = std::atof(number.data());
	if (this->_double < 1000000 && this->_double > -1000000)
	{
		coma += 1 + sign;
		while (number.data()[coma] == '0')
			coma++;
		if (!number.data()[coma])
			this->_displayComaZero = 1;
	}
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
			std::cout << static_cast<char>(this->_int);
			break ;

		case (FLOAT) :
			if (this->_float < MIN_CHAR || this->_float > MAX_CHAR)
			{
				std::cout << "char overflow" << std::endl;
				return ;
			}
			if (this->_float <= 31 || this->_float >= 127)
			{
				std::cout << "char " << static_cast<int>(this->_float) << " isn't displayable" << std::endl;
				return ;
			}
			std::cout << static_cast<char>(this->_float);
			break;
		
		case (DOUBLE) :
			if (this->_double < MIN_CHAR || this->_double > MAX_CHAR)
			{
				std::cout << "char overflow" << std::endl;
				return ;
			}
			if (this->_double <= 31 || this->_double >= 127)
			{
				std::cout << "char " << static_cast<int>(this->_double) << " isn't displayable." << std::endl;
				return ;
			}
			std::cout << static_cast<char>(this->_double);
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
			std::cout << static_cast<int>(this->_char);
			break ;
		
		case (FLOAT) :
			if (this->_float > MAX_INT || this->_float < MIN_INT)
			{
				std::cout << "int overflow" << std::endl;
				return ;
			}
			std::cout << static_cast<int>(this->_float);
			break ;

		case (DOUBLE) :
			if (this->_double > MAX_INT || this->_double < MIN_INT)
			{
				std::cout << "int overflow." << std::endl;
				return ;
			}
			std::cout << static_cast<int>(this->_double);
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
			std::cout << static_cast<float>(this->_char);
			break ;
		
		case (INT) :
			std::cout << static_cast<float>(this->_int);
			break ;

		case(DOUBLE) :
			std::cout << static_cast<float>(this->_double);
			break ;
		
		default :
			std::cout << this->_float;
	}
	if (this->_displayComaZero)
		std::cout << ".0";
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
			std::cout << static_cast<double>(this->_char);
			break ;
		
		case (INT) :
			std::cout << static_cast<double>(this->_int);
			break ;

		case(FLOAT) :
			std::cout << static_cast<double>(this->_float);
			break ;
		
		default :
			std::cout << this->_double;
	}
	if (this->_displayComaZero)
		std::cout << ".0";
	std::cout << std::endl;
}
