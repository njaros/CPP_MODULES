/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:12 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:57:57 by njaros           ###   ########lyon.fr   */
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

void	Bureaucrat::signForm(Form &form)
{
	// If I exactly do what the french subject ask me to do, they're is the absurd and useless code :
	/*
	if (form.getSigned())
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	else
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		if (this->getGrade() > form.getSignGrade())
			std::cout << "his grade is too low (grade required is " << form.getSignGrade() << ")." << std::endl;
		else
			std::cout << "the problem is between the keyboard and the chair." << std::endl;
	}
	*/

	// Here is the most logically thing to do :
	if (form.getSigned())
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because he's already signed" << std::endl;
	else
	{
		if (form.getSignGrade() < this->getGrade())
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade is too low" << std::endl;
		else
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "." << std::endl;
	}
	catch(Form::GradeTooLow const& e)
	{
		std::cout << e.what() << " for " << this->getName() << " to execute the form " << form.getName() << "." << std::endl;
	}
	catch(Form::NotSignedException const& e)
	{
		std::cout << this->getName() << " couldn't execute. " << e.what() << " : " << form.getName() << "." << std::endl;
	}
}