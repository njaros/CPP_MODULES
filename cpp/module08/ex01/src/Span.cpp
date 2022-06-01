#include "../includes/Span.hpp"

Span::Span() : _size(0), _idx(0)
{}

Span::Span(unsigned int size) : _size(size), _idx(0)
{
	this->_vector = new int[size];
}

Span::Span( Span const &other )
{
	*this = other;
}

Span::~Span()
{
	delete this->_vector;
}

Span	&Span::operator=( Span const &other )
{
	int	i = 0;

	this->_size = other.getSize();
	this->_idx = other.getIdx();
	delete this->_vector;
	this->_vector = new int[this->_size];
	while (i < this->_size)
	{
		this->_vector[i] = other.getVector()[i];
		i++;
	}
}

unsigned int	Span::getSize()	const
{
	return (this->_size);
}

unsigned int	Span::getIdx()	const
{
	return (this->_idx);
}

int	*Span::getVector()	const
{
	return (this->_vector);
}

void	Span::AddNumber(int n)
{
	if (this->_idx == this->_size)
		throw ("Vector is full");
	this->_vector[_idx] = n;
	this->_idx += 1;
}

long int	Span::shortestSpan()	const
{
	
}