#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkSecret;
		std::string	_number;

	public:
		Contact();
		~Contact();

		void putFirstName(std::string firstName);
		void putLastName(std::string lastName);
		void putNickName(std::string nickName);
		void putSecret(std::string darkSecret);
		void putNumber(std::string number);

		std::string	getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getSecret() const;
		std::string getNumber() const;
};


#endif