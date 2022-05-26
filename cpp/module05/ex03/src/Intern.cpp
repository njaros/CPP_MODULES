/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:14:47 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 13:41:42 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern( void )
{}

Intern::Intern( Intern const &other)
{
	(void) other;
}

Intern::~Intern( void )
{}

Intern	&Intern::operator=(Intern const &other)
{
	(void) other;
	return (*this);
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	int	i;
	std::string	toCompare[3] = {"ShrubberyCreationForm", "RobotomyRequestForm" , "PresidentialPardonForm"};
	Form	*newForm;	

	newForm = NULL;
	i = -1;
	while (++i < 3 && name.compare(toCompare[i]));
	switch (i)
	{
		case 0 :
			newForm = new ShrubberyCreationForm(target);
			break;
		case 1 :
			newForm = new RobotomyRequestForm(target);
			break;
		case 2 :
			newForm = new PresidentialPardonForm(target);
			break;
		default :
			std::cout << "An intern tried to do an unknow form : " << name << "." << std::endl;
	}
	if (i < 3)
		std::cout << "An intern create a form : " << name << "." << std::endl;
	return (newForm);
}