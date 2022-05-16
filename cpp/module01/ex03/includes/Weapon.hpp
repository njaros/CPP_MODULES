/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:21:34 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 11:18:24 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string.h>

class Weapon
{
	public :

		Weapon( std::string type );
		~Weapon( void );
		std::string	&getType( void );
		void		setType( std::string newType );

	private :

		std::string	_type;

};

#endif
