/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:35 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 09:34:35 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat luc("Luc", 150);
		luc.incrGrade();
		std::cout << luc << std::endl;
		bob.decrGrade();
		std::cout << bob << std::endl;
		bob.incrGrade();
		bob.incrGrade();
		std::cout << "this message won't be written";
	}
	catch(Bureaucrat::GradeTooHigh const& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLow const& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "this message will be written" << std::endl;
	
	try
	{
		Bureaucrat bob("bob", 151);
		std::cout << "this message won't be written";
	}
	catch(Bureaucrat::GradeTooHigh const& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLow const& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "this message will be written" << std::endl;

	try
	{
		Bureaucrat bob("bob", 75);
		bob.incrGrade();
		bob.incrGrade();
		bob.incrGrade();
		std::cout << bob << std::endl;
	}
	catch(Bureaucrat::GradeTooHigh const& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLow const& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "When destructor has been called ?" << std::endl;
	return (0);
}
