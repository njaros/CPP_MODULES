/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:58:33 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 13:04:57 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
T const	&min(T const &a, T const &b)
{
	return(a < b ? a : b);
}

template< typename T >
T const	&max(T const &a, T const &b)
{
	return(a > b ? a : b);
}

template< typename T >
void	swap(T &a, T &b)
{
	T	temp = a;
	a = b;
	b = temp;
}

#endif