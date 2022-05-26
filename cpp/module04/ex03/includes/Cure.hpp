/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:35:00 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 13:23:20 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
	public :

		Cure(void);
		Cure(Cure const &other);
		~Cure(void);

		virtual void		use(ICharacter& target);
		virtual AMateria*	clone( void )	const;

		using AMateria::operator=;

	private :

	

};

#endif