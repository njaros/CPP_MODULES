#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Form
{
	public :

		Form(std::string name, int signGrade, int execGrade);
		Form(Form const &other);
		~Form(void);

		Form		&operator=(Form cont &other);
		std::string	getName(void)		const;
		int			getSignGrade(void)	const;
		int			getExecGrade(void)	const;
		bool		getSigned(void)		const;
		void		beSigned(Bureaucrat const &bur);
		class		GradeTooLow : public std::exception
		{
			public :

				char const	*what( void ) const throw;
		};

	private :

		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
		Form(void);

}

std::ostream	&operator<<(std::ostream &o, Form &form);

#endif