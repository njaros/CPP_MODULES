#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	this->ScavTrap::setName(std::string("unnamed") + "_clap_name");
	this->FragTrap::setName(std::string("unnamed") + "_clap_name");
	this->_name = "unnamed";
	this->ScavTrap::setClassName("DiamondTrap");
	this->FragTrap::setClassName("DiamondTrap");
	this->FragTrap::setHp(100);
	this->ScavTrap::setEp(50);
	this->FragTrap::setAd(30);
	std::cout << "DiamondTrap default constructor : An unnamed DiamondTrap has been created, it shines a lot !" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name )
{
	this->ScavTrap::setName(name + "_clap_name");
	this->FragTrap::setName(name + "_clap_name");
	this->_name = name;
	this->ScavTrap::setClassName("DiamondTrap");
	this->FragTrap::setClassName("DiamondTrap");
	this->FragTrap::setHp(100);
	this->ScavTrap::setEp(50);
	this->FragTrap::setAd(30);
	std::cout << "DiamondTrap constructor : A DiamondTrap named " << this->ScavTrap::getName() << " has been created, it shines a lot!" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &other ) : FragTrap(), ScavTrap()
{
	this->ScavTrap::setName(other.ScavTrap::getName());
	this->FragTrap::setName(other.FragTrap::getName());
	this->_name = other._name;
	this->ScavTrap::setClassName(other.ScavTrap::getClassName());
	this->FragTrap::setClassName(other.FragTrap::getClassName());
	this->FragTrap::setHp(other.FragTrap::getHp());
	this->ScavTrap::setEp(other.ScavTrap::getEp());
	this->FragTrap::setAd(other.FragTrap::getAd());
	std::cout << "DiamondTrap copy constructor : A DiamondTrap named " << this->ScavTrap::getName() << " has been copied, it shines a lot!" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap Destructor from  " << this->ScavTrap::getClassName() << " " << this->ScavTrap::getName() << " : called, we can wear off the sun glasses." << std::endl;
}

void	DiamondTrap::whoAmI( void )	const
{
	std::cout << "My ClapTrap name is " << this->ScavTrap::getName() << " and my DiamondTrap name is " << this->_name << std::endl;
}
