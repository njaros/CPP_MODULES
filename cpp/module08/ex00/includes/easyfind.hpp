/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:59:28 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 18:48:20 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
# define EASY_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>

template < typename T >
int	easyfind(T cont, int n)
{
	std::iterator<T>	p;
	p = std::find(cont.begin(), cont.end(), n);
	if (p == cont.end())
		throw ("not found");
	return (p);
}

#endif