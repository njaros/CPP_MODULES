/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:27:47 by njaros            #+#    #+#             */
/*   Updated: 2022/05/16 19:07:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <ostream>
#include <iostream>

int	main(int ac, char **av)
{
	std::string		str;
	std::string		s1;
	std::string		s2;
	std::ifstream	ifs;
	std::ofstream	ofs;
	size_t			found;
	char			buff;

	if (ac != 4)
		return (1);
	ifs.open(av[1], std::ifstream::in);
	if (ifs.fail())
		return (1);
	buff = ifs.get();	
	while (ifs.good())
	{
		str.append(&buff);
		buff = ifs.get();
	}
	ifs.close();
	s1 = av[2];
	s2 = av[3];
	found = str.find(s1);
	while (!s1.empty() && found != std::string::npos)
	{
		str.erase(found, s1.length());
		str.insert(found, s2);
		found += s2.length();
		found = str.find(s1, found);
	}
	s1 = av[1];
	s1.append(".replace");
	ofs.open(s1, std::ofstream::out | std::ofstream::trunc);
	ofs.write(str.data(), str.length());
	ofs.close();
	return (0);
}
