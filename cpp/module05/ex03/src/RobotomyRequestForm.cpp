/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:24 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 10:36:36 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyRequestForm", 72, 45), _target("noTarget")
{}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &other ) : Form(other), _target(other.getTarget())
{}

RobotomyRequestForm::~RobotomyRequestForm( void )
{}

std::string	RobotomyRequestForm::getTarget( void )	const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLow();
	else if (!this->getSigned())
		throw NotSignedException();
	else
	{
		std::srand(time(NULL));
		std::cout << " BrrrBrrr zzzzzzzzzzttt *crouic* ......" << std::endl;
		if (std::rand() % 2)
			std::cout << this->getTarget() << " has been robotomised." << std::endl;
		else
			std::cout << "robotomasation failed on " << this->getTarget() << "." << std::endl; 
	}
}