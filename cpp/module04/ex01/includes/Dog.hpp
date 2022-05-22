#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public :

		Dog( void );
		Dog( std::string name );
		Dog( Dog const& other );
		virtual ~Dog( void );

		virtual void	makeSound( void )	const;

	private :


};

#endif