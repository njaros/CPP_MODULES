/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:40:33 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:40:34 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie* zombiePtr;
	int		i;
	
	if (N <= 0)
		return (NULL);
	zombiePtr = new Zombie[N];
	i = -1;
	while (++i < N)
		zombiePtr[i].setName(name);
	return (zombiePtr);
}
