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
int easyfind(const T &cont, const int n) //Only works with containers !!
{
	int	idx = -1;
	typename T::const_iterator it = cont.cbegin();
	--it;
	while (++it != cont.cend())
	{
		idx++;
		if (*it == n)
			return (idx);
	}
	throw ("not found");
}

#endif