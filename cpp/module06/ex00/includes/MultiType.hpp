/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MultiType.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:39:31 by njaros            #+#    #+#             */
/*   Updated: 2022/05/30 16:15:17 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITYPE_HPP
# define MULTITYPE_HPP

# include "writingInType.hpp"

class	MultiType
{
	public :

		MultiType( void );
		MultiType(std::string number, int type);
		MultiType(MultiType const &other);
		~MultiType( void );

		MultiType	&operator=(MultiType const &toher);

		int		getType( void )	const;
		char	getCharValue( void )	const;
		int		getIntValue( void )	const;
		float	getFloatValue( void )	const;
		double	getDoubleValue( void )	const;
		bool	getErrIntValue( void )	const;
		int		getErrFloatValue( void )	const;
		int		getErrDoubleValue( void )	const;
		bool	getNanValue( void )	const;

		void	displayChar( void );
		void	displayInt( void );
		void	displayFloat( void );
		void	displayDouble( void );

	private :

		void	setChar(std::string number);
		void	setInt(std::string number);
		void	setFloat(std::string number);
		void	setDouble(std::string number);
		char 	_char;
		int 	_int;
		float	_float;
		double 	_double;
		int 	_type;
		bool	_errInt;
		int		_errFloat;
		int		_errDouble;
		bool	_nan;
		
};

#endif