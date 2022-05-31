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

template < typename T >
void	iter(T *adr, unsigned int size, void (*f)(T&))
{
	unsigned int	idx = 0;
	while (idx < size)
	{
		(*f)(adr[idx]);
		idx ++;
	}
}

#endif