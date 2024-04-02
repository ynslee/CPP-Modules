#pragma once

# include <map>
# include <iostream>

class Bitcoin{
	private:
		std::map<std::string, double> _data;
		Bitcoin();
		Bitcoin(Bitcoin const &other);
		Bitcoin &operator=(Bitcoin const &other);

	public:
		Bitcoin (std::string filename);
		~Bitcoin();
		int validate_data();
		int inputFileParsing(std::string filename);
		void calculateAndPrint(std::string date, double value);


	class WrongValueException : public std::exception {
	public:
		const char* what() const throw() override{
			return ("Value in data.csv is wrong");
		};
	};
};