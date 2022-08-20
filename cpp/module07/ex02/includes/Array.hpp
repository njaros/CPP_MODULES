/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:52:35 by njaros            #+#    #+#             */
/*   Updated: 2022/08/20 16:43:35 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

class	InvalidIndexException : public std::exception
		{
			public :
				char const	*what( void ) const throw() { return ("This index is out of border."); }
		};

template < typename T = int >
class Array
{
	public :

		Array(void) : _array(0), _size(0) {}
		Array(unsigned int n) : _size(n)
		{ 
			this->_array = new T[n];
		}
		Array(Array const &other) { *this = other; }
		~Array( void ) { delete []this->_array; }

		Array	&operator=( Array const &other )
		{
			unsigned int	idx = -1;
			this->_size = other.size();
			this->_array = new T[this->_size];
			while (++idx < this->_size)
				this->_array[idx] = other[idx];
			return (*this);
		}

		T	&operator[]( unsigned int idx )
		{
			if (idx >= this->_size)
			{
				throw InvalidIndexException();
			}
			return (this->_array[idx]);
		}

		const T	&operator[]( unsigned int idx )	const
		{
			if (idx >= this->_size)
			{
				throw InvalidIndexException();
			}
			return (this->_array[idx]);
		}

		unsigned int	size( void )	const { return (this->_size); }
		 
	private :

		T				*_array;
		unsigned int	_size;
		

};

#endif