/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:46:58 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 10:46:59 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public :

		Animal( void );
		Animal( std::string name );
		Animal( Animal const& other );
		virtual ~Animal( void );

		std::string			getName( void )	const;
		void				setName( std::string name );
		virtual void		makeSound( void )	const;

	private :

		std::string	_name;

	protected :

		std::string	type;

};

#endif