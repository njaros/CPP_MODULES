#include "Zombie.hpp"

int	main( int ac, char **av )
{
	Zombie*	michel;
	int		i;
	int		n;

	if (ac != 3)
		return (0);
	i = -1;
	n = atoi(av[1]);
	michel = zombieHorde(n, av[2]);
	while (++i < n)
		michel[i].announce();
	delete [] michel;
	return (0);
}
