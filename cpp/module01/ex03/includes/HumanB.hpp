/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:41:17 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:41:18 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "../includes/Weapon.hpp"

class HumanB
{
	public :

		HumanB( std::string name );
		~HumanB( void );
		void	setWeapon( Weapon &weapon );
		void	attack( void )	const;

	private :

		std::string	const	_name;
		Weapon				*_weapon;

};

#endif
