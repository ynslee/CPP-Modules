#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <ctime>

Bitcoin::Bitcoin(std::string filename) {
	if (validate_data() == -1)
	{
		std::cerr << "input data cannot be opened or datas are incorrect" << std::endl;
		throw WrongValueException();
	}
	if (inputFileParsing(filename) == -1)
		return ;
}

Bitcoin::Bitcoin(Bitcoin const &other) {
	*this = other;
}

Bitcoin	&Bitcoin::operator=(Bitcoin const &other){
	this->_data = other._data;
	return (*this);
}

Bitcoin::~Bitcoin(){};

static bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static int isValidDate(const std::string &date){
	std::tm  tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail() || !ss.eof())
		return (-1);
	int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(tm.tm_year + 1900))
		daysMonth[1] = 29;
	if (tm.tm_mon < 0 || tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > daysMonth[tm.tm_mon])
        return (-1);
	return (0);
}

int Bitcoin::validate_data(){
	int i = 0;
	std::ifstream file("./data.csv");
	if (!file.is_open())
		return (-1);
	std::string line;
	while(std::getline(file, line))
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Invalid parameter in the data.csv" << std::endl;
			file.close();
			return (-1);
		}
		std::string date = line.substr(0, pos);
		if (isValidDate(date) == -1)
		{
			std::cerr << "Invalid date in the data.csv" << std::endl;
			file.close();
			return (-1);
		}
		long double value;
		try{
			value = std::stod(line.substr(pos + 1));
		} catch (std::exception &e){
			std::cerr << &e << std::endl;
			file.close();
			return (-1);
		}
		_data[date] = value;
	}
	file.close();
	if (i == 0)
	{
		std::cerr << "file is empty" << std::endl;
		return (-1);
	}
	return (0);
}

int Bitcoin::inputFileParsing(std::string fileName)
{
	std::string date;
	long double value;

	std::string line;
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
	{
		std::cerr << "cannot open the file!" << std::endl;
		return(-1);
	}
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "input file does not following format: 'date | value' " << std::endl;
		file.close();
		return (-1);
	}
	int i = 0;
	while (std::getline(file, line))
	{
		if (i == 0)
			i = 1;
		if (line.length() <= 13)
		{
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		else
		{
			size_t pos = line.find('|');
			std::string date = line.substr(0, pos - 1);
			if (isValidDate(date) == -1)
			{
				std::cerr << "Error : bad input =>" << date << std::endl;
				continue ;
			}
			std::string strValue = line.substr(pos + 2);
			value = 0;
			try{
				value = std::stod(strValue);
			} catch (std::exception &e){
				(void)e;
				std::cout << "Error : bad input => " << date << std::endl;
				continue ;
			}
			if (value < 0)
			{
				std::cerr << "Error : not a positive number." << std::endl;
				continue ;
			}
			if (value > static_cast<long double>(1000))
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue ;
			}
			calculateAndPrint(date, value);
		}
	}
	if (i == 0)
	{
		std::cerr << "file is empty" << std::endl;
		return (-1);
	}
	return (0);
}

void Bitcoin::calculateAndPrint(std::string date, long double value){
	
	std::map<std::string, long double>::iterator itlow;

	itlow = _data.lower_bound(date);
	long double rate = itlow->second;
	std::cout << date << " => " << value << " = " << rate * value << std::endl;
}