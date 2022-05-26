/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:11:46 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 11:23:44 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public :

		MateriaSource(void);
		MateriaSource(MateriaSource const &other);
		~MateriaSource( void );

		MateriaSource	&operator=(MateriaSource const &other);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

	private :

		AMateria	*_inventory[4];
};

#endif