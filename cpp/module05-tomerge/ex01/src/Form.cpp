#include "../includes/Form.hpp"

Form::Form(void)
{}

Form::Form(std::string name, int signGrade, int exeGrade) : _name(name), _signGrade(signGrade), _execGrade(exeGrade), _signed(0)
{}

Form::Form(Form const &other) : _name(other.getname()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()), _signed(other.getSigned())
{}

Form::~Form(void)
{}

Form	&Form::operator=(Form const &other)
{
	//do nothing because of constants privates members
	return (*this);
}

std::string	Form::getName(void)	const
{
	return (this->_name);
}

int	Form::getExecGrade(void)	const
{
	return (this->_execGrade);
}

int	Form::getSignGrade(void)	const
{
	return (this->_signGrade);
}

bool	Form::getSigned(void)	const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat const &bur)
{
	if (bur.getGrade() > this->getSignGrade)
		throw GradeTooLow();
	else
		this->_signed = 1;
}

char const	*Form::GradeTooLow::what(void) const throw()
{
	return ("Grade is too low to sign this form");
}

std::ostream	&operator<<(std::ostream &o, Form const &form)
{
	o << "Form : " << form.getName() << " | min grade to sign : " << form.getSignGrade() << " | min grade to execute : " << form.getExecGrade() << std::endl;
	return (o)
}