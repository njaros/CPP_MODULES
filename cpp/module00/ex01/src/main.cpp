
#include "phonebook.hpp"

int	routine(void)
{
	PhoneBook	redfish;
	std::string	buffer;
	int			roll;
	int			memUsed;

	memUsed = 0;
	roll = 0;
	while (1)
	{
		std::cout << std::endl;
		std::cout << "You can type \"ADD\", \"SEARCH\", \"EXIT\"";
		std::cout << " if you want to add a contact, search a contact or exit (not a contact) : ";
		std::getline(std::cin, buffer);
		std::cout << std::endl;
		if (!buffer.compare("ADD"))
		{
			redfish.ftAdd(roll);
			if (roll == 7)
				roll = 0;
			else
				roll++;
			if (memUsed < 8)
				memUsed++;
		}
		else if (!buffer.compare("SEARCH"))
			redfish.ftSearch(memUsed);
		else if (!buffer.compare("EXIT"))
			return (0);
	}
	return (0);
}

int	main(void)
{
	int	i;

	std::cout << std::endl;
	i = routine();
	std::cout << std::endl;
}