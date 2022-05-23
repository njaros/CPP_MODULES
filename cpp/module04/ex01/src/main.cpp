/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:35 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 18:14:59 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main( void )
{
	Cat		*dina = new Cat("Dina");
	Cat		*dina2 = new Cat;
	Dog		*medor = new Dog("Medor");

	dina->makeSound();
	medor->makeSound();

	dina->getBrain().setIdea(3, "What if I chase a mouse ?");
	std::cout << dina->getBrain().getIdea(2) << std::endl;
	*dina2 = *dina;
	std::cout << dina2->getBrain().getIdea(3) << std::endl;

	Cat		dina3 = *dina2;
	std::cout << dina3.getBrain().getIdea(3) << std::endl;

	delete (dina);
	delete (dina2);
	delete (medor);
	return (0);
}