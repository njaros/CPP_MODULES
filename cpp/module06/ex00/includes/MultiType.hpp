/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MultiType.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:39:31 by njaros            #+#    #+#             */
/*   Updated: 2022/05/27 16:59:08 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITYPE_HPP
# define MULTITYPE_HPP

# include "writingInType.hpp"

class	MultiType
{
	public :

		MultiType( void );
		MultiType(char c);
		MultiType(int i);
		MultiType(float f);
		MultiType(double d);
		MultiType(MultiType const &other);
		~MultiType( void );

		MultiType	&operator=(MultiType const &toher);

		int		getType( void )			const;
		char	getCharValue( void )	const;
		int		getIntValue( void )		const;
		float	getFloatValue( void )	const;
		double	getDoubleValue( void )	const;

		/*void	charToInt( void );
		void	charToFloat( void );
		void	charToDouble( void );

		void	intToChar( void );
		void	intToFloat( void );
		void	intToDouble( void );

		void	floatToChar( void );
		void	floatToInt( void );
		void	floatToDouble( void );

		void	doubleToChar( void );
		void	doubleToInt( void );
		void	doubleToFloat( void );*/

		void	displayChar( void );
		void	displayInt( void );
		void	displayFloat( void );
		void	displayDouble( void );

	private :

		char 	_char;
		int 	_int;
		float	_float;
		double 	_double;
		int 	_type;
		
};

#endif