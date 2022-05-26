/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:28:21 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 15:27:11 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

# include <iostream>
# include <string.h>

class	ICharacter;

class	AMateria
{
	protected :

		std::string const	_type;

	public :
	
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		virtual ~AMateria( void );

		AMateria& operator=( AMateria const &other );

		std::string const &getType( void )	const; //Returns the materia type

		virtual AMateria*	clone( void )	const = 0;
		virtual void		use(ICharacter& target);

	private :

		AMateria(void);
};

#endif
