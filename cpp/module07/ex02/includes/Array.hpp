/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:52:35 by njaros            #+#    #+#             */
/*   Updated: 2022/09/08 09:51:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template < typename T = int >
class Array
{
	public :

		Array(void) : _array(0), _size(0) {}
		Array(const unsigned int n) : _size(n)
		{
            if (n)
			    this->_array = new T[n];
			else
				this->_array = 0;
		}
		Array(Array const &other) { *this = other; }
		~Array( void ) {
			if (_array)
			{
				delete []this->_array;
				_array = 0;
			}
		}

		Array	&operator=( Array const &other )
		{
			unsigned int	idx = -1;

			if (&other == this)
				return (*this);
            delete []this->_array;
			this->_size = other.size();
            if (this->_size)
			    this->_array = new T[this->_size];
            else
                this->_array = NULL;
			while (++idx < this->_size)
				this->_array[idx] = other[idx];
			return (*this);
		}

        class	InvalidIndexException : public std::exception
        {
            public :
                char const	*what( void ) const throw() { return ("This index is out of border."); }
        };

		T	&operator[]( const unsigned int idx )
		{
			if (idx >= this->_size)
			{
				throw InvalidIndexException();
			}
			return (this->_array[idx]);
		}

		const T	&operator[]( const unsigned int idx )	const
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