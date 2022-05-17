/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:14:14 by njaros            #+#    #+#             */
/*   Updated: 2022/05/17 11:17:48 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <stdlib.h>

class Harl
{
	public :

		Harl( void );
		~Harl( void );
		void	complain( std::string level );
	
	private :

		void	error( void );
		void	warning( void );
		void	info( void );
		void	debug( void );

};

#endif
