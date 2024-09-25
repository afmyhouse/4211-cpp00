#include "PhoneBook.hpp"
#include <stdlib.h>

void header(void)
{
	std::cout << " ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗\n"
			  << " ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝ \n"
			  << " ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ \n"
			  << " ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n"
			  << " ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗ \n"
			  << " ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ \n"
			  << std::endl;
}

int main(void)
{
	system("clear");
	header();
	PhoneBook	pb;
	std::string	input;

	pb = PhoneBook();
	while(1) {
		pb._displayMenu();
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		else if (!input.compare("ADD"))
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			break;
		else
			pb._displayInvalid();
	}
	system("clear");
}
