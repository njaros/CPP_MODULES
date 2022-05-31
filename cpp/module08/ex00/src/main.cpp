/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:36:57 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 18:39:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main()
{
	int	idx = 0;
	std::vector<int> a(12, 20);

	idx = easyfind(a, 4);
	std::cout << idx << std::endl;
}