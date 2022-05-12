
#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	redfish;
	char		buffer[6];
	int			roll;
	int			memUsed;

	memUsed = 0;
	roll = 0;
	while (1)
	{
		std::cout << "You can type \"ADD\", \"SEARCH\", \"EXIT\"";
		std::cout << " if you want to add a contact, search a contact or exit (not a contact) :";
		std::cin >> buffer;
		std::cout << std::endl;
		if (!strcmp(buffer, "ADD"))
		{
			redfish.ftAdd(roll);
			if (roll == 7)
				roll = 0;
			else
				roll++;
			if (memUsed < 7)
				memUsed++;
		}
		else if (!strcmp(buffer, "SEARCH"))
			redfish.ftSearch(memUsed);
		else if (!strcmp(buffer, "EXIT"))
			return (0);
	}
	return (0);
}