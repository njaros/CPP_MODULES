/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:06 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:42:46 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

# include "Form.hpp"
# include <time.h>
# include <stdlib.h>

class	RobotomyRequestForm : public Form
{
	public :

		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const &other );
		virtual ~RobotomyRequestForm( void );

		using			Form::operator=;
		std::string		getTarget( void )	const;
		virtual void	execute(Bureaucrat const &executor) const;

	private :
	
		std::string const	_target;

		RobotomyRequestForm( void );
};

#endif