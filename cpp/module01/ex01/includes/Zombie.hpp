/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:40:21 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:40:22 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string.h>
# include <stdlib.h>

class Zombie
{
	public :

		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void	setName( std::string name );
		void	announce( void )	const;

	private :

		std::string	_zombieName;

};

Zombie*	zombieHorde( int N, std::string name );

#endif