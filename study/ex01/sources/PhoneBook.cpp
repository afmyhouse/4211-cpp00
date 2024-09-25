#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_i = 0;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add(void) {
	std::string fn, ln, nn, pn, ds;
	int add = 1;
	std::cout << "\n█ ADD   █████  PROVIDE CONTACT INFORMATION  ████████████████\n" << std::endl;

	while (add) {
		// std::cout << " First Name    :  ";
		fn = validString(" Enter First Name    >  ");
		if (fn.empty())
			break ;

		// std::cout << " Last Name     :  ";
		ln = validString(" Enter Last Name     >  ");
		if (ln.empty())
			break ;

		// std::cout << " Nickname      :  ";
		nn = validString(" Enter Nickname      >  ");
		if (nn.empty())
			break ;

		// std::cout << " Phone number  :  ";
		pn = validNumber(" Enter Phone number  :  ");
		if (pn.empty())
			break ;

		// std::cout << " Darkest Secret:  ";
		ds = validString(" Enter Darkest Secret:  ");
		if (ds.empty())
			break ;
		add = 0;
	}
	if (add) {
		this->_displayInvalid();
	}
	else {

		this->_contacts[this->_i++ % MAX_CONTACTS] = Contact(fn, ln, nn, pn, ds);
		std::cout << "\n██████  CONTACT SAVED  ██████████████████████████████\n" << std::endl;
	}
	return ;
}

bool PhoneBook::_isStringPrintable(std::string str) {
	for (size_t i = 0; i< str.size(); i++)
		if (!isprint(str[i]))
			return false;
	return true;
}

void PhoneBook::_displayPhoneBook(void) {
	std::string field;

	std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i< MAX_CONTACTS; i++) {
		std::cout << "|" <<std::setw(10) << i << "|";
		// field = this->_contacts[i].getFirstName();
		std::cout << std::setw(10) << Contact::formatField(this->_contacts[i].getFirstName()) << "|";
		field = this->_contacts[i].getLastName();
		std::cout << std::setw(10) << Contact::formatField(field) << "|";
		field = this->_contacts[i].getNickName();
		std::cout << std::setw(10) << Contact::formatField(field) << "|" << std::endl;
	}
}

void PhoneBook::_displayPrompt(std::string prompt) {
	std::cout << "\nPhoneBook : " << prompt;
}

void PhoneBook::_displayMenu(void) {
	std::cout << "██████  Phonebook Options  ██████████████████████████" << std::endl;
	std::cout << std::endl;
	std::cout << "        > ADD" << std::endl;
	std::cout << "        > SEARCH" << std::endl;
	std::cout << "        > EXIT" << std::endl;
	this->_displayPrompt("Enter your OPTION > ");
}

void PhoneBook::search(void) {
	int id;
	int maxId;

	maxId = this->_i > 7 ? 7 : this->_i - 1;

	this->_displayPhoneBook();
	this->_displayPrompt("Select id > ");
	std::cin >> id;
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	if (std::cin.fail()) {
		this->_displayInvalid();
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} else if (id < 0 || id > maxId) {
		std::cout << "\n██████  NO CONTACT AT INDEX " << id << "  ██████████████████████\n" << std::endl;
	} else {
		this->_contacts[id].displayContact();
	}
}

void PhoneBook::_displayInvalid(void) {
	std::cout << "\n██ ERROR : invalid input\n" << std::endl;
}

std::string PhoneBook::validString(std::string prompt1) {

	int retries = 3;
	int error = 0;
	std::string s;
	std::string prompt = "Enter a valid " + prompt1 + " > ";

	while (retries > 0) {
		retries--;
		std::cout << prompt;
		std::cin.clear();
		std::getline(std::cin, s, '\n');
		if (isEmptyField(s) )
			error = 1;
		for (size_t i = 0; i < s.size(); i++) {
			if (!isprint(s[i]) || isspace(s[i]) || !isalnum(s[i])) {
				std::cout << "\n██ ERROR : only printable, alphanumeric chars\n" << std::endl;
				error = 1;
			}
		}
		if (!error)
			return (s);
		error = 0;
	}
	return (NULL);
}
std::string PhoneBook::validNumber(std::string prompt1) {

	int retries = 3;
	int error = 0;
	std::string s;
	std::string prompt = "Enter a valid " + prompt1 + " > ";

	while (retries > 0) {
		retries--;
		std::string prompt = "Enter a valid string > ";
		std::cin.clear();
		std::getline(std::cin, s, '\n');
		if (isEmptyField(s) )
			error = 1;
		for (size_t i = 0; i < s.size(); i++) {
			if (!isdigit(s[i])){
				std::cout << "\n██ ERROR : only digits [0..9]\n" << std::endl;
				error = 1;
				}
			}
		if (!error)
			return (s);
		error = 0;
	}
	return (NULL);
}

int PhoneBook::isEmptyField(std::string s) {
	if (s.length() < 1) {
		std::cout << "\n██ ERROR :  field can't be empty\n" << std::endl;
		return (1);
	}
	return (0);
}