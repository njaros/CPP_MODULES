#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->setClassName("ScavTrap");
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
	std::cout << "ScavTrap default constructor : An unnamed ScavTrap has been created" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->setClassName("ScavTrap");
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
	std::cout << "ScavTrap constructor : A ScavTrap named " << this->getName() << " has been created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &other ) : ClapTrap( other )
{
	std::cout << "ScavTrap copy constructor : A ScavTrap named " << this->getName() << " has been copied" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor from  " << this->getClassName() << " " << this->getName() << " : called" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << this->getClassName() << " " << this->getName() << " has entering Gate Keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEp() && this->getHp())
	{
		std::cout << this->getClassName() << " " << this->getName() << " did " << this->getAd() << " damages while trying to hugging to " << target << std::endl;
		this->useEnergy(1);
	}
	else if (!this->getHp())
		std::cout << this->getClassName() << " " << this->getName() << " couldn't hug " << target << " because he's too injured." << std::endl;
	else if (!this->getEp())
		std::cout << this->getClassName() << " " << this->getName() << " couldn't hug " << target << " because he's too exhausted." << std::endl;
}
