/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:54:01 by njaros            #+#    #+#             */
/*   Updated: 2022/05/24 10:21:17 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class	Character : public ICharacter
{

	public :

		Character(void);
		Character(std::string name);
		Character(Character const &other);
		virtual ~Character(void);

		Character &operator=( Character const &other );

		virtual std::string const	&getName() const;
		virtual void 				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);

	private :

		AMateria	*_inventory[4];
		std::string	_name;
	
};

#endif