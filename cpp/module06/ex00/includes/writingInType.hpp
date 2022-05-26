/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writingInType.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:10:15 by njaros            #+#    #+#             */
/*   Updated: 2022/05/26 17:29:24 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITINGINTYPE_HPP
# define WRITINGINTYPE_HPP

# include <iostream>
# include <string>
# include <limits>

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define MAX_CHAR std::numeric_limits<char>::max()
# define MIN_CHAR std::numeric_limits<char>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()

void	writeInt(std::string str);
void	writeChar(std::string str);
void	writeFloat(std::string str);
void	writeDouble(std::string str);
bool	isLitteral(std::string str);

#endif