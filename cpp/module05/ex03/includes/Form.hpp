/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:33:59 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:41:48 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public :

		Form(std::string name, int signGrade, int execGrade);
		Form(Form const &other);
		virtual ~Form(void);

		Form			&operator=(Form const &other);
		std::string		getName(void)		const;
		int				getSignGrade(void)	const;
		int				getExecGrade(void)	const;
		bool			getSigned(void)		const;
		void			beSigned(Bureaucrat const &bur);
		virtual	void	execute(Bureaucrat const &executor)	const = 0;
		
		class		GradeTooLow : public std::exception
		{
			public :

				char const	*what( void ) const throw();
		};
		class		GradeTooHigh : public std::exception
		{
			public :

				char const	*what( void ) const throw();
		};
		class		NotSignedException : public std::exception
		{
			public :
				char const	*what( void ) const throw();
		};

	private :

		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
		Form(void);

};

std::ostream	&operator<<(std::ostream &o, Form &form);

#endif