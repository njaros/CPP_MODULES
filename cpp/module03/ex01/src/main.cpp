#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main(void)
{
	int			loop;
	ClapTrap	a;
	ClapTrap	b("njaros");
	ClapTrap	c(b);
	ClapTrap	bullier("bullier");
	ScavTrap	u;
	ScavTrap	cheese("fromage");
	ScavTrap	cheese2(cheese);
	ScavTrap	ham("jambon");

	loop = -1;
	while (++loop < 12)
	{
		if (a.getEp())
		{
			a.attack(b.getName());
			b.takeDamage(a.getAd());
		}
		else
			a.attack(b.getName());
	}
	c.takeDamage(80);
	loop = -1;
	while (++loop < 10)
	{
		bullier.attack(c.getName());
		c.takeDamage(bullier.getAd());
		c.beRepaired(3);
	}
	b.takeDamage(9);
	bullier.takeDamage(9);
	bullier.beRepaired(9);
	loop = -1;
	while (++loop < 11)
		b.beRepaired(2);
	u.beRepaired(1);
	cheese.attack(ham.getName());
	ham.takeDamage(ham.getAd());
	ham.guardGate();
	return (0);
}
