/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:14:50 by njaros            #+#    #+#             */
/*   Updated: 2022/05/31 13:49:41 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

void	plusUn(int &val)
{
	val += 1;
}

void	toUpperChar(char &c)
{
	c = (char)std::toupper(c);
}

template < typename T >
void    displayConst(const T &fou)
{
    std::cout << fou;
}

void    displayNotConst(std::string &fou)
{
    fou.append("frog");
    std::cout << fou;
}

int	main(void)
{

    //Easy test with not class variable and not const

	int tab[] = {1, 2, 3, 4};
	int	*ptr = &tab[0];
    char	str[] = "FraiseD444333oibs";
    iter(str, std::strlen(str), toUpperChar);
	iter(ptr, 4, plusUn);

	std::cout << tab[0] << tab[1] << tab[2] << tab[3] << "\n";
    std::cout << str << "\n\n";

    //Ugly test with string class const or not, with const function or not

    const std::string constStrs[] = {"hello ", "you can't ", "modify ", "me\n"};
    std::string notConstStrs[] = {"hello ", "I ", "love ", "frogs\n"};

    iter(constStrs, 4, displayConst);
    iter(notConstStrs, 4, displayConst);
    iter(notConstStrs, 4, displayNotConst);
    std::cout << "\n\n";
    //iter(constStrs, 4, displayNotConst); // <--- This row is just here to explain the const behaviours
}
