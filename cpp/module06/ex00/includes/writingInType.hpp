/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writingInType.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:10:15 by njaros            #+#    #+#             */
/*   Updated: 2022/08/16 15:57:11 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITINGINTYPE_HPP
# define WRITINGINTYPE_HPP

# include <iostream>
# include <string>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_INT_STR "2147483647"
# define MIN_INT_STR "-2147483648"
# define MAX_CHAR 127
# define MIN_CHAR -128
# define MAX_FLOAT "340282346638528859811704183484516925440.000000"
# define MIN_FLOAT "-340282346638528859811704183484516925440.000000"
# define MAX_DOUBLE "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000"
# define MIN_DOUBLE "-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000"
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4

bool		isNum(char c);
bool		isLitteral(std::string str, int &type);
bool		isLitteralException(std::string str, int &type);
void		eraseFirstsZeros(std::string &str);
std::string	toUpperStr(std::string str);

#endif