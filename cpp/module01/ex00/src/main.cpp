#include "Zombie.hpp"

int	main( void )
{
	Zombie*	Michel;
	Zombie* Benoit;

	Michel = newZombie("Michel");
	Benoit = newZombie("Benoit");

	randomChump("Tatie Daniele");

	Michel->announce();

	delete Michel;
	delete Benoit;
	return (0);
}