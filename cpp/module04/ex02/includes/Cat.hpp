/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:04 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 18:09:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :

		Cat( void );
		Cat( std::string name );
		Cat( Cat const& other );
		virtual ~Cat( void );

		Cat&	operator=( const Cat& other );

		virtual void	makeSound( void )	const;
		Brain			&getBrain( void )	const;

	private :

		Brain	*_brain;

};

#endif