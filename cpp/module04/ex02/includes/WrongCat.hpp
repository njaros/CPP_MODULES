/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <njaros@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:20 by njaros            #+#    #+#             */
/*   Updated: 2022/05/23 17:14:35 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :

		WrongCat( void );
		WrongCat( std::string name );
		WrongCat( WrongCat const& other );
		virtual ~WrongCat( void );

		using WrongAnimal::operator=;

		void	makeSound( void )	const;

	private :


};

#endif