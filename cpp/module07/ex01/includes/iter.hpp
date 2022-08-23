/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:09:24 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 13:40:22 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

//The subject said to do one function iter, but we need to do one iter function for const,
// and another one for not const

template < typename T >
void	iter(const T *adr, unsigned int size, void (*f)(const T&))
{
	unsigned int	idx = 0;
	while (idx < size)
	{
		(*f)(adr[idx]);
		idx++;
	}
}

template < typename T >
void    iter(T *adr, unsigned int size, void (*f)(T&))
{
    unsigned int	idx = 0;
    while (idx < size)
    {
        (*f)(adr[idx]);
        idx++;
    }
}


//The next template is here to explain the const behaviours
/*
template < typename T >
void    iter(const T *adr, unsigned int size, void (*f)(T&))
{
    (void) f;
    (void) size;
    (void) adr;
    std::cout << "I'm sorry, I'm not sure your function will not modify my variable\n\n";
}
*/
#endif