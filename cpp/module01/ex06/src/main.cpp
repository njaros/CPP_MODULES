#include "Harl.hpp"

int main (int ac, char **av)
{
	Harl		pouet;
	int			i;
	std::string	str;
	
	(void) ac;
	i = 0;
	while (av[++i])
	{
		str = av[i];
		pouet.complain(str);
	}
	return 0;
}
