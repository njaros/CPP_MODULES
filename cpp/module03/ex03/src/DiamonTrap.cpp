#include "../includes/DiamonTrap.hpp"

DiamonTrap::DiamonTrap( void ) : ScavTrap()
{
	this->FragTrap::setName(std::string("unnamed") + "_clap_name");
	this->ScavTrap::setName(std::string("unnamed") + "_clap_name");
	this->_name = "unnamed";
	this->FragTrap::setClassName("DiamonTrap");
	this->FragTrap::setHp(100);
	this->ScavTrap::setEp(50);
	this->FragTrap::setAd(30);
	std::cout << "DiamonTrap default constructor : An unnamed DiamonTrap has been created, it shines a lot !" << std::endl;
}

DiamonTrap::DiamonTrap( std::string name ) : FragTrap( name + "_clap_name" )
{
	this->ScavTrap::setName(std::string(name) + "_clap_name");
	this->_name = name;
	this->FragTrap::setClassName("DiamonTrap");
	this->FragTrap::setHp(100);
	this->ScavTrap::setEp(50);
	this->FragTrap::setAd(30);
	std::cout << "DiamonTrap constructor : A DiamonTrap named " << this->ScavTrap::getName() << " has been created, it shines a lot!" << std::endl;
}

DiamonTrap::DiamonTrap( DiamonTrap const &other ) : ScavTrap( other )
{
	this->_name = other._name;
	std::cout << "DiamonTrap copy constructor : A DiamonTrap named " << this->ScavTrap::getName() << " has been copied, it shines a lot!" << std::endl;
}

DiamonTrap::~DiamonTrap( void )
{
	std::cout << "DiamonTrap Destructor from  " << this->ScavTrap::getClassName() << " " << this->ScavTrap::getName() << " : called, we can wear off the sun glasses." << std::endl;
}

void	DiamonTrap::whoAmI( void )	const
{
	std::cout << "My ClapTrap name is " << this->ScavTrap::getName() << " and my DiamonTrap name is " << this->_name << std::endl;
}
