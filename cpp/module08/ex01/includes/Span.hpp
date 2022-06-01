#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class Span
{

	public :

		//Coplien fonctions

		Span(unsigned int);
		Span( Span const & other );
		~Span();

		Span	&operator=( Span const & other );

		//Span fonctions

		void			AddNumber(int);
		long int		shortestSpan()	const;
		long int		longestSpan()	const;

		//Geters

		unsigned int	getSize()		const;
		unsigned int	getIdx()		const;
		int				*getVector()	const;

	private :

		unsigned int	_size;
		int				*_vector;
		unsigned int	_idx;
		Span();

};

#endif