#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public :

		Animal( void );
		Animal( std::string name );
		Animal( Animal const& other );
		virtual ~Animal( void );

		std::string			getName( void )	const;
		void				setName( std::string name );
		virtual void		makeSound( void )	const;

	private :

		std::string	_name;

	protected :

		std::string	type;

};

#endif