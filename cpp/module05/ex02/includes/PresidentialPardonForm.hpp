/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:03 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:42:40 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARDON_HPP
# define PARDON_HPP

# include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	public :

		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &other );
		virtual ~PresidentialPardonForm( void );
		
		using			Form::operator=;
		std::string		getTarget( void )	const;
		virtual void	execute(Bureaucrat const &executor) const;

	private :

		std::string const	_target;

		PresidentialPardonForm( void );
};

#endif