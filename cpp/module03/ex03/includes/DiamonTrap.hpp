#ifndef DiamonTrap_HPP
# define DiamonTrap_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamonTrap : public FragTrap, public ScavTrap
{
	public :

		DiamonTrap( void );
		DiamonTrap( std::string name );
		DiamonTrap( DiamonTrap const &other );
		~DiamonTrap( void );

		using	FragTrap::operator=;
		using	ScavTrap::attack;

		void	whoAmI( void )	const;

	private :

		std::string			_name;

};

#endif