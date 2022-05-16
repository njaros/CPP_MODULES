#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string.h>
#include "Weapon.hpp"

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
