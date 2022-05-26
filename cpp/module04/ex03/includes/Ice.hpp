/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:52:29 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 13:38:17 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
	public :

		Ice(void);
		Ice(Ice const &other);
		~Ice(void);

		virtual void		use(ICharacter& target);
		virtual AMateria*	clone( void )	const;

		using AMateria::operator=;

	private :

	

};

#endif