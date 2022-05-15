#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string.h>

class Zombie
{
	public :

		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void	setName( std::string name );
		void	announce( void )	const;

	private :

		std::string	_zombieName;

};

Zombie*	zombieHorde( int N, std::string name );

#endif