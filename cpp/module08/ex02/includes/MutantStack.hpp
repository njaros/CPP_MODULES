/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:09:54 by njaros            #+#    #+#             */
/*   Updated: 2022/06/28 17:02:29 by njaros           ###   ########lyon.fr   */
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

		iterator	begin()
		{
			return (this->c.begin());
		}
		iterator	end()
		{
			return (this->c.end());
		}
	
		
};

#endif