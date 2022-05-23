/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:08 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 18:16:38 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public :

		Dog( void );
		Dog( std::string name );
		Dog( Dog const& other );
		virtual ~Dog( void );

		Dog&	operator=( const Dog& other );

		virtual void	makeSound( void )	const;
		Brain			&getBrain( void )	const;

	private :

		Brain	*_brain;

};

#endif