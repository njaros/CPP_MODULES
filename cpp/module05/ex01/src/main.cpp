/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:35:03 by njaros            #+#    #+#             */
/*   Updated: 2022/07/20 14:49:14 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

void	tryToSign(Form &form, Bureaucrat &bur)
{
	try
	{
		form.beSigned(bur);
	}
	catch(Form::GradeTooHigh const& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooLow const& e)
	{
		std::cout << e.what() << std::endl;
	}
	bur.signForm(form);
}

int main(void)
{
	try
	{
		Bureaucrat	bob("Bob", 12);
		Bureaucrat	luc("Luc", 15);
		Form		a("a38", 13, 15);
	//	Form		b("b27", 0, 2);
		Form		c("c15", 150, 150);
		tryToSign(a, luc);
		tryToSign(a, bob);
		bob.signForm(c);
	}
	catch(Bureaucrat::GradeTooHigh const& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLow const& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHigh const& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooLow const& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
