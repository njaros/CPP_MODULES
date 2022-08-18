/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:21 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:49:15 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("PresidentialPardonForm", 25, 5), _target("noTarget")
{}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &other ) : Form(other), _target(other.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm( void )
{}

std::string	PresidentialPardonForm::getTarget( void )	const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)	const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLow();
	else if (!this->getSigned())
		throw NotSignedException();
	else
		std::cout << this->getTarget() << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}