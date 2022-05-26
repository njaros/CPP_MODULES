/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:15 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 10:03:04 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(void) : _name("noName"), _signGrade(1), _execGrade(0) 
{}

Form::Form(std::string name, int signGrade, int exeGrade) : _name(name), _signGrade(signGrade), _execGrade(exeGrade)
{
	if (this->getExecGrade() < 1 || this->getSignGrade() < 1)
		throw GradeTooHigh();
	if (this->getExecGrade() > 150 || this->getSignGrade() > 150)
		throw GradeTooLow();
	this->_signed = 0;
}

Form::Form(Form const &other) : _name(other.getName()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
	this->_signed = other.getSigned();
}

Form::~Form(void)
{}

Form	&Form::operator=(Form const &other)
{
	//do nothing because of constants privates members
	(void) other;
	return (*this);
}

std::string	Form::getName(void)	const
{
	return (this->_name);
}

int	Form::getExecGrade(void)	const
{
	return (this->_execGrade);
}

int	Form::getSignGrade(void)	const
{
	return (this->_signGrade);
}

bool	Form::getSigned(void)	const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat const &bur)
{
	if (bur.getGrade() > this->getSignGrade())
		throw GradeTooLow();
	else
		this->_signed = 1;
}

char const	*Form::GradeTooLow::what(void) const throw()
{
	return ("Grade is too low");
}

char const	*Form::GradeTooHigh::what(void) const throw()
{
	return ("Grade is too high");
}

char const	*Form::NotSignedException::what(void) const throw()
{
	return ("This form is not signed");
}

std::ostream	&operator<<(std::ostream &o, Form const &form)
{
	o << "Form : " << form.getName() << " | min grade to sign : " << form.getSignGrade() << " | min grade to execute : " << form.getExecGrade() << std::endl;
	return (o);
}