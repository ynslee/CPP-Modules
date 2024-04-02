#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <ctime>

Bitcoin::Bitcoin(std::string filename) {
	if (validate_data() == -1)
	{
		std::cerr << "input data cannot be opened or datas are incorrect" << std::endl;
		exit(1);
	}
	if (inputFileParsing(filename) == -1)
	{
		std::cerr << "input data cannot be opened or datas are incorrect" << std::endl;
		exit(1);
	}
}

Bitcoin::~Bitcoin(){};

static bool isValidDate(const std::string &date){
	std::tm  tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail() || !ss.eof())
	{
		std::cerr << "Date is incorrect in the data.csv" << std::endl;
		return (-1);
	}
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
		double value;
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
}

int Bitcoin::inputFileParsing(std::string fileName)
{
	std::string date;
	double value;

	std::string line;
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
	{
		std::cerr << "cannot open the file!" << std::endl;
		return(-1);
	}
	getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "input file does not following format: 'date | value' " << std::endl;
		file.close();
		return (-1);
	}
	int i = 0;
	while (getline(file, line))
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
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
			double value;
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
			else if (static_cast<int>(value) > INT_MAX || static_cast<int>(value) < INT_MIN)
			{
				std::cerr << "Error: too larget a number." << std::endl;
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
}

void Bitcoin::calculateAndPrint(std::string date, double value){
	
}