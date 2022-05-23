/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:40:01 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:40:02 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	Michel;
	Zombie* Benoit;

	Michel = newZombie("Michel");
	Benoit = newZombie("Benoit");

	randomChump("Tatie Daniele");

	Michel->announce();

	delete Michel;
	delete Benoit;
	return (0);
}