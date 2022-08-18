/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:38 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:15:04 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (this->getGrade() > 150)
		throw GradeTooLow();
	if (this->getGrade() < 1)
		throw GradeTooHigh();
	std::cout << "Welcome " << *this << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &other)
{
	this->setGrade(other.getGrade());
	return (*this);
}

int	Bureaucrat::getGrade( void )	const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName( void )	const
{
	return (this->_name);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
	else
		this->_grade = grade;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bur)
{
	o << bur.getName() << ", grade : " << bur.getGrade();
	return (o);
}

char const	*Bureaucrat::GradeTooHigh::what(void) const throw()
{
	return ("Grade too high, can't be better than 1");
}

char const	*Bureaucrat::GradeTooLow::what(void) const throw()
{
	return ("Grade too low, can't set more than 150");
}

void	Bureaucrat::incrGrade( void )
{
	this->setGrade(this->getGrade() - 1);
}

void	Bureaucrat::decrGrade( void )
{
	this->setGrade(this->getGrade() + 1);
}