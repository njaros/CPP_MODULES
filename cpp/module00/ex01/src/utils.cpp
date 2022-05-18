#include "../includes/Phonebook.hpp"

void	secureGetline(std::string *buffer)
{
	while (!std::getline(std::cin, *buffer))
	{
			std::cin.clear();
			clearerr(stdin);
	}
}
