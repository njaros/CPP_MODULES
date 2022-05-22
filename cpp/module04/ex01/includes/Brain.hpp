#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string.h>

class brain
{
	public :

		Brain( void );
		Brain( Brain const& other );
		~Brain( void );

		Brain &operator=( Brain const& other );
		void		setIdea( unsigned int i, std::string idea );
		std::string	getIdea( unsigned int i )	const;

	private :

		std::string	_ideas[100];
}

#endif