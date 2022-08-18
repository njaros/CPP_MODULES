/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:09 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:48:43 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUB_HPP
# define SHRUB_HPP

# include "Form.hpp"
# include <fstream>

class	ShrubberyCreationForm : public Form
{
	public :

		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const &other );
		virtual ~ShrubberyCreationForm( void );
		
		using			Form::operator=;
		std::string		getTarget( void )	const;
		virtual void	execute(Bureaucrat const &executor)	const;

	private :

		std::string const	_target;

		ShrubberyCreationForm( void );
};

#endif