/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:26 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 11:30:40 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreationForm", 145, 137), _target("noTarget")
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &other ) : Form(other), _target(other.getTarget())
{}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{}

std::string	ShrubberyCreationForm::getTarget( void )	const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	std::ofstream	ofs;
	std::string		shrubbery;
	shrubbery.append("                     - - -\n");
	shrubbery.append("                   -        -  -     --    -\n");
	shrubbery.append("                -                 -         -  -\n");
	shrubbery.append("                                -\n");
	shrubbery.append("                               -                --\n");
	shrubbery.append("               -          -            -              -\n");
	shrubbery.append("               -            '-,        -               -\n");
	shrubbery.append("               -              'b      *\n");
	shrubbery.append("               -              'b      *\n");
	shrubbery.append("               -    -           $:   #:               -\n");
	shrubbery.append("             --      -  --      *#  @):        -   - -\n");
	shrubbery.append("                          -     :@,@):   ,-**:'   -\n");
	shrubbery.append("              -      -,         :@@*: --**'      -   -\n");
	shrubbery.append("                       '#o-    -:(@'-@*\"'  -\n");
	shrubbery.append("               -  -       'bq,--:,@@*'   ,*      -  -\n");
	shrubbery.append("                          ,p$q8,:@)'  -p*'      -\n");
	shrubbery.append("                   -     '  - '@@Pp@@*'    -  -\n");
	shrubbery.append("                    -  - --    Y7'.'     -  -\n");
	shrubbery.append("                              :@):.\n");
	shrubbery.append("                             .:@:'.\n");
	shrubbery.append("                           .::(@:.      -Sam Blumenstein-\n");
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLow();
	else if (!this->getSigned())
		throw NotSignedException();
	else
	{
		ofs.open(this->getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
		ofs.write(shrubbery.data(), shrubbery.length());
		ofs.close();
	}
}
