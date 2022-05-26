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
		void		setName(std::string name);
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

		std::string	_name;
		int			_grade;
		Bureaucrat(void);

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bur);

#endif