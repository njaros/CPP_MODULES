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

template < typename T >
int easyfind(T &cont, int n) //Only works whit containers !!
{
	int	idx = -1;
	typename T::iterator it = cont.begin();
	--it;
	while (++it != cont.end())
	{
		idx++;
		if (*it == n)
			return (idx);
	}
	throw ("not found");
}

#endif