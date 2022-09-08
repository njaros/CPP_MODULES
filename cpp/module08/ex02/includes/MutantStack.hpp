/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:09:54 by njaros            #+#    #+#             */
/*   Updated: 2022/08/25 09:19:38 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
# define MUTANT_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <stdlib.h>
# include <string>
# include <deque>

template < typename T >
class	MutantStack : public std::stack<T>
{
	public :

		MutantStack() {}
		MutantStack( MutantStack const &other )
		{
			*this = other;
		}
		~MutantStack() {}
		MutantStack &operator=(MutantStack const &other)
		{
			this->c = other.c;
			return *this;
		}
		
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}
		iterator	end()
		{
			return (this->c.end());
		}
        const_iterator  cbegin()    const
        {
            return (this->c.cbegin());
        }
        const_iterator  cend()  const
        {
            return (this->c.cend());
        }
	
		
};

#endif