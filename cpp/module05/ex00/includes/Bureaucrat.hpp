/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:34:31 by njaros            #+#    #+#             */
/*   Updated: 2022/08/18 10:14:43 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat
{
	public:

		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		Bureaucrat	&operator=(Bureaucrat const &other);
	

		void	incrGrade( void );
		void	decrGrade( void );

		int			getGrade( void )	const;
		std::string	getName( void )		const;
		void		setGrade( int grade );
		class		GradeTooHigh : public std::exception
		{
			public :

				char const	*what( void ) const throw();

		};
		class		GradeTooLow : public std::exception
		{
			public :

				char const	*what( void ) const throw();

		};
	
	private:

		std::string const	_name;
		int					_grade;
		Bureaucrat(void);

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bur);

#endif