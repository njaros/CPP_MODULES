#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string.h>

class Zombie
{
	public :

		Zombie( std::string name );
		~Zombie( void );

		void	announce( void )	const;

	private :

		const std::string	_zombieName;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif