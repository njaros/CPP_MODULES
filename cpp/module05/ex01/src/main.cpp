/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:35:03 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:37:32 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat	bob("Bob", 12);
		Bureaucrat	luc("Luc", 15);
		Form		a("a38", 13, 15);
	//	Form		b("b27", 0, 2);
		Form		c("c15", 150, 150);
		Form		d("exception", 1, 1);
		bob.signForm(a);
		luc.signForm(a);
		bob.signForm(d);
		std::cout << std::endl << "Scope not stopped." << std::endl << std::endl;
		d.beSigned(bob);
		std::cout << "Forced stop of the scope" << std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
