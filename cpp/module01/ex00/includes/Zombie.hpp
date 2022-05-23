/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:39:54 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:39:55 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string.h>

class Zombie
{
	public :

		Zombie( std::string name );
		~Zombie( void );

		void	announce( void )	const;

	private :

		const std::string	_zombieName;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif