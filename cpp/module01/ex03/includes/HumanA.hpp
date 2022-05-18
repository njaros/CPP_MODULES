/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:14:30 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 11:09:30 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "../includes/Weapon.hpp"

class HumanA
{
	public :

		HumanA( std::string name, Weapon &weapon );
		~HumanA( void );
		void	attack( void )	const;

	private :

		std::string const	_name;
		Weapon				&_weapon;

};

#endif
