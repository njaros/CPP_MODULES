#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public :

		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const &other );
		~DiamondTrap( void );

		void	whoAmI( void )	const;

	private :

		std::string			_name;

};

#endif