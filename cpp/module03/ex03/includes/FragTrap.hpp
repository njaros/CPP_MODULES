#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :

		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const &other );
		~FragTrap( void );

		using	ClapTrap::operator=;

		void		highFivesGuys( void );

};

#endif