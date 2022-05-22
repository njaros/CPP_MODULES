#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :

		WrongCat( void );
		WrongCat( std::string name );
		WrongCat( WrongCat const& other );
		virtual ~WrongCat( void );

		void	makeSound( void )	const;

	private :


};

#endif