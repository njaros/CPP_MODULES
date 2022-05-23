/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:59 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 17:33:49 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string.h>

class Brain
{
	public :

		Brain( void );
		Brain( Brain const& other );
		~Brain( void );

		Brain &operator=( Brain const& other );
		void		setIdea( unsigned int i, std::string idea );
		std::string	getIdea( unsigned int i )	const;

	private :

		std::string	_ideas[100];
};

#endif
