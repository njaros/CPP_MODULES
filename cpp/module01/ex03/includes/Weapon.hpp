#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string.h>

class Weapon
{
	public :

		Weapon( void );
		~Weapon( void );
		std::string	&getType( void )	const;
		void		setType( std::string newType );

	private :

		std::string	type;
}

#endif