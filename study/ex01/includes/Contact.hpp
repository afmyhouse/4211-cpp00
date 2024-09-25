#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

# define CLEAR_SCREEN "\033[2J\033[H"

class Contact {
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void displayContact(void);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);

		static std::string formatField(std::string field);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkSecret;
};

#endif