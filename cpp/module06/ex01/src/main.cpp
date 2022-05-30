/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:55:15 by njaros            #+#    #+#             */
/*   Updated: 2022/05/30 17:07:20 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/serial.hpp"

uintptr_t	serialize(Data* ptr)
{
	return((uintptr_t) ptr);
}

Data*	deserialize(uintptr_t raw)
{
	Data	*recover;

	recover = (Data *)raw;
	return(recover);
}

int	main()
{
	Data		*pouet;
	uintptr_t	serial;
	Data		*pouetbis;

	pouet = new (Data);
	pouet->cheeseType = "Reblochon";
	pouet->numberOfCheese = 4;
	serial = serialize(pouet);
	pouetbis = deserialize(serial);
	std::cout << pouetbis->cheeseType << " " << pouetbis->numberOfCheese << std::endl;
	delete (pouet);
}