#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <ctime>

Bitcoin::Bitcoin(std::string filename) {
	if (validate_data() == -1)
	{
		std::cerr << "data from data.csv is incorrect" << std::endl;
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
			return (-1);
		}
		std::string date = line.substr(0, pos);
		if (isValidDate(date) == -1)
		{
			std::cerr << "Invalid date in the data.csv" << std::endl;
			return (-1);
		}
		double value;
		try{
			value = std::stod(line.substr(pos + 1));
		} catch (std::exception &e){
			std::cerr << &e << std::endl;
			return (-1);
		}
		_data[date] = value;
	}
	file.close();
}                                                                                                       