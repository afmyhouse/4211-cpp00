#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) {
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickName = nn;
	this->_phoneNumber = pn;
	this->_darkSecret = ds;
}

void Contact::displayContact(void) {
	std::cout << std::endl;
	std::cout << "██████  Contact Information  ████████████████████████" << std::endl;
	std::cout << "_____________________________________________________" <<std::endl;
	std::cout << " First Name  : \"" << this->_firstName << "\"" << std::endl;
	std::cout << " Last Name   : \"" << this->_lastName << "\"" << std::endl;
	std::cout << " Nickname    : \"" << this->_nickName << "\"" << std::endl;
	std::cout << " Phone       : \"" << this->_phoneNumber << "\"" << std::endl;
	std::cout << " Dark Secret : \"" << this->_darkSecret << "\"" << std::endl;
	std::cout << "_____________________________________________________" <<std::endl;
	std::cout << std::endl;
}

std::string Contact::formatField(std::string field) {
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

std::string Contact::getFirstName(void) {
	return (this->_firstName);
}

std::string Contact::getLastName(void) {
	return (this->_lastName);
}

std::string Contact::getNickName(void) {
	return (this->_nickName);
}
