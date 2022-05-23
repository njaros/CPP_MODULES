/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:46:58 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 18:23:09 by njaros           ###   ########lyon.fr   */
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
		virtual ~Animal( void ) = 0;

		Animal	&operator=( const Animal& other );

		std::string			getName( void )	const;
		std::string			getType( void )	const;
		void				setName( std::string name );
		virtual void		makeSound( void )	const;

	private :

		std::string	_name;

	protected :

		std::string	type;

};

#endif