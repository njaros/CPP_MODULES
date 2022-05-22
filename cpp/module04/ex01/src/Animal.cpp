#include "../includes/Animal.hpp"

Animal::Animal( void ) : _name("noName")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string name ) : _name(name)
{
	std::cout << "Animal constructor called : " << this->getName() << " is born." << std::endl;
}

Animal::Animal( Animal const& other ) : _name(other.getName())
{
	std::cout << "Animal copy constructor called : " << this->getName() << " has been cloned" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called : " << this->getName() << " escaped." << std::endl;
}

std::string	Animal::getName( void )	const
{
	return (this->_name);
}

void	Animal::setName( std::string name )
{
	this->_name = name;
}

void	Animal::makeSound( void )	const
{
	std::cout << this->type << this->getName() << " : ?????UNDEFINED????" << std::endl;
}
