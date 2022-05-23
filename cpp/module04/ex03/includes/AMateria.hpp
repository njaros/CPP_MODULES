/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:28:21 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 18:33:36 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class	AMateria
{
	protected :

		std::string	type;

	public :
		AMateria(std::string const &type);

		std::string const &getType()	const; //Returns the materia type

		virtual AMateria*	clone()	const = 0;
		virtual void		use(ICharacter& target);
};

#endif
