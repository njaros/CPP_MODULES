#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _zombieName(name)
{
	std::cout << "Constructor message > " << this->_zombieName << ": constructed." << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Destructor message > " << this->_zombieName << ": destroyed." << std::endl;
}

void	Zombie::setName ( std::string name )
{
	this->_zombieName = name;
}

void	Zombie::announce( void )	const
{
	std::cout << this->_zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
