/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:19 by njaros            #+#    #+#             */
/*   Updated: 2022/06/02 15:20:39 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

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
	Intern	njaros;
	Form	*test;
	Form	*test2;
	Bureaucrat	regis("Regis de la compta", 5);
	Bureaucrat	benoit("Benoit de la cafet", 140);

	test = njaros.makeForm("pouet", "Michel");
	test = njaros.makeForm("ShrubberyCreationForm", "Francine");
	tryToSign(*test, regis);
	benoit.executeForm(*test);
	test2 = njaros.makeForm("PresidentialPardonForm", "Benoit de la cafet");
	tryToSign(*test2, benoit);
	regis.executeForm(*test2);
	delete (test2);
	delete (test);
	return (0);
}
