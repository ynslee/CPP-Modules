#include "Contact.hpp"

Contact::Contact() {
	return;
}

Contact::~Contact(){
	return ;
}

void Contact::putFirstName(std::string firstName){
	this->_firstName = firstName;
}

void Contact::putLastName(std::string lastName){
	this->_lastName = lastName;
}

void Contact::putNickName(std::string nickName){
	this->_nickName = nickName;
}

void Contact::putSecret(std::string darkSecret){
	this->_darkSecret = darkSecret;
}

void Contact::putNumber(std::string number){
	this->_number = number;
}

std::string	Contact::getFirstName() const {
	return(this->_firstName);
}

std::string	Contact::getLastName() const {
	return(this->_lastName);
}

std::string	Contact::getNickName() const {
	return(this->_nickName);
}

std::string	Contact::getSecret() const {
	return(this->_darkSecret);
}

std::string	Contact::getNumber() const {
	return(this->_number);
}