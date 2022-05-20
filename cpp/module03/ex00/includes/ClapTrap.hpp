#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string.h>
#include <iostream>

class ClapTrap
{
	public :

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &other );
		~ClapTrap( void );

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName( void )	const;
		int			getHp( void )	const;
		int			getEp( void )	const;
		int			getAd( void )	const;

	private :

		std::string	_name;
		int			_healthPoints;
		int			_energyPoints;
		int			_attackDamage;

};

#endif