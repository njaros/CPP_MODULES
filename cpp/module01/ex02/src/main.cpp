#include <iostream>
#include <string.h>

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = str;

	stringPTR = &str;
	std::cout << "My program has to print:" << std::endl;
	std::cout << "The memory address of the string variable :" << &str << std::endl;
	std::cout << "The memory address held by stringPTR :" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF :" << &stringREF << std::endl;
	std::cout << "And then:" << std::endl;
	std::cout << "The value of the string variable :" << str << std::endl;
	std::cout << "The value pointed to by stringPTR :" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF :" << stringREF << std::endl;
	return (0);
}