/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:19 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 12:00:37 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

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
		Bureaucrat	luc("Luc", 5);
		PresidentialPardonForm		a("Michel");
		ShrubberyCreationForm		b("pelouz");
		RobotomyRequestForm			c("hamster");
		tryToSign(a, luc);
		tryToSign(b, bob);
		tryToSign(c, bob);
		bob.executeForm(a);
		luc.executeForm(a);
		bob.executeForm(b);
		bob.executeForm(c);
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
