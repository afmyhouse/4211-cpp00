#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(void);
		void search(void);
		void _displayMenu(void);
		void _displayPrompt(std::string prompt);
		void _displayPhoneBook(void);
		bool _isStringPrintable(std::string str);
		void _displayInvalid(void);
		std::string validString(std::string prompt);
		std::string validNumber(std::string prompt);
		int isEmptyField(std::string s);
	private:
		int _i;
		static const int MAX_CONTACTS = 8;
		Contact _contacts[MAX_CONTACTS];
};

#endif