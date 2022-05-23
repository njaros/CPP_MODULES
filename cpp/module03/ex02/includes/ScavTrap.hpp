/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:46:15 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 15:33:08 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &other );
		~ScavTrap( void );

		using	ClapTrap::operator=;

		void		guardGate( void );
		void		attack(const std::string& target);

};

#endif