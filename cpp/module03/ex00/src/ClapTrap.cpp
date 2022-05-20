#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("unnamed"), _healthPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor : An unnamed ClapTrap has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _healthPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor : A ClapTrap named " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &other ) : _name(other._name), _healthPoints(other._healthPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor : A ClapTrap named " << this->_name << " has been copied" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor : The ClapTrap " << this->_name << " has been deleted" << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->_energyPoints && this->_healthPoints)
	{
		std::cout << "ClapTrap " << this->getName() << " did " << this->_attackDamage << " damages to " << target << std::endl;
		this->_energyPoints -= 1;
	}
	else if (!this->_healthPoints)
		std::cout << "ClapTrap " << this->getName() << " couldn't attack " << target << " because he's too injured." << std::endl;
	else if (!this->_energyPoints)
		std::cout << "ClapTrap " << this->getName() << " couldn't attack " << target << " because he's too exhausted." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_healthPoints)
	{
		std::cout << "The poor ClapTrap " << this->getName() << " is getting bullied..." << std::endl;
		return ;
	}
	this->_healthPoints -= amount;
	std::cout << "ClapTrap " << this->getName() << " took " << amount << " damages";
	if (this->_healthPoints <= 0)
	{
		this->_healthPoints = 0;
		std::cout << " and he's KO !" << std::endl;
	}
	else
		std::cout << ", he has " << this->_healthPoints << " HP left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints && this->_healthPoints)
	{
		std::cout << "ClapTrap " << this->getName() << " is repairing himself and gain " << amount << " health points.";
		this->_healthPoints += amount;
		this->_energyPoints -= 1;
		std::cout << " He has now " << this->_healthPoints << " hp." << std::endl;
	}
	else if (!this->_healthPoints)
		std::cout << "Claptrap " << this->getName() << " is to injuried to be able to repair himself." << std::endl;
	else
		std::cout << "ClapTrap " << this->getName() << " couldn't repair himself because he's too exhausted." << std::endl;
}

std::string	ClapTrap::getName( void )	const
{
	return (this->_name);
}

int	ClapTrap::getHp( void )	const
{
	return (this->_healthPoints);
}

int	ClapTrap::getEp( void )	const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAd( void )	const
{
	return (this->_attackDamage);
}