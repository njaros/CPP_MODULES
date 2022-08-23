/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:06:48 by njaros            #+#    #+#             */
/*   Updated: 2022/08/23 18:02:17 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <exception>

class Span
{

	public :

		//Coplien fonctions

		Span(unsigned int);
		Span( Span const & other );
		~Span();

		Span	&operator=( Span const & other );

		//Span fonctions

		void			addNumber(int);
		long int		shortestSpan()	const;
		long int		longestSpan()	const;
		template < typename inputIteror >
		void			insert(inputIteror begin, inputIteror last)
		{
			if (static_cast<long>(_size - _vector.size()) - (last - begin) < 0)
				throw (std::out_of_range("not enought space on this span's container"));
			_vector.insert(_vector.end(), begin, last);
		}

		//Geters

		unsigned int		getSize()	const;

	private :

		unsigned int		_size;
		std::vector<int>	_vector;
		Span();

};

#endif