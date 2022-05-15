#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* zombiePtr;
	int		i;
	
	if (N <= 0)
		return (NULL);
	zombiePtr = new Zombie[N];
	i = -1;
	while (++i < N)
		zombiePtr[i].setName(name);
	return (zombiePtr);
}
