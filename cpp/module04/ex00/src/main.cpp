/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:35 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:47:36 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main( void )
{
	Cat		*dina = new Cat("dina");
	Animal	*jeanpascal = new Animal("Jean Pascal");
	Animal	*porc = new Cat();	// <---- Upcast, compilateur is OK
	Dog		*medor = new Dog("Medor");
	Animal	*medor2 = new Dog(*medor);	// <---- Upcast, compilateur is OK
	//Cat		*orion = new Animal(*dina); <-- Downcast, compilateur will refuse
	WrongAnimal	*croco = new WrongAnimal("Croco");
	WrongAnimal *tipoune = new WrongCat("Tipoune");
	WrongCat	*neightboorscat = new WrongCat("Neighboor's cat");	

	dina->makeSound();
	jeanpascal->makeSound();
	porc->makeSound();
	medor->makeSound();
	medor2->makeSound();
	croco->makeSound();
	tipoune->makeSound();
	neightboorscat->makeSound();

	delete (dina);
	delete (jeanpascal);
	delete (porc);
	delete (medor);
	delete (medor2);
	delete (croco);
	delete (tipoune);
	delete (neightboorscat);
	return (0);
}