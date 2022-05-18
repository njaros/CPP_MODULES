#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <iomanip>

# define FIRSTNAME_ 1
# define LASTNAME_ 2
# define NICKNAME_ 3
# define PHONENUMBER_ 4
# define DARKESTSECRET_ 5

class Contact
{
	public :

		Contact(void); //Constructeur
		~Contact(void); //Destructeur

		void		set_value(int context, std::string str);
		std::string	get_value(int context);

	private :

		// I could use std::string instead of char[]
		// anyway I learned a lot about string member fonctions to convert to char[].
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	
};

#endif
