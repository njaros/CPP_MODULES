/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:55:15 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 17:22:19 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/serial.hpp"

uintptr_t	serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
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