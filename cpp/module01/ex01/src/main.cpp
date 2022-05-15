#include "Zombie.hpp"

int	main( void )
{
	Zombie*	Michel;

	Michel = zombieHorde(5, "Michel");

	delete Michel;
	return (0);
}