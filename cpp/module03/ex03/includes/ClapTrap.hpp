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
		void		useEnergy(unsigned int amount);
		std::string	getName( void )	const;
		std::string	getClassName( void )	const;		
		int			getHp( void )	const;
		int			getEp( void )	const;
		int			getAd( void )	const;
		void		setName( std::string name );
		void		setClassName( std::string name );
		void		setHp( unsigned int value );
		void		setEp( unsigned int value );
		void		setAd( int value );

	private :

		std::string					_name;
		std::string					_className;
		int							_healthPoints;
		int							_energyPoints;
		int							_attackDamage;


};

#endif