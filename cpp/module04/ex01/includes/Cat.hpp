#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public :

		Cat( void );
		Cat( std::string name );
		Cat( Cat const& other );
		virtual ~Cat( void );

		virtual void	makeSound( void )	const;

	private :


};

#endif