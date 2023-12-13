
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sstream>

static int isDirectory(char *_fileName)
{
	struct stat fileStat;

	if (stat(_fileName, &fileStat) == 0)
	{
		if (S_ISDIR(fileStat.st_mode))
		{
			std::cout << _fileName << " is a directory." << std::endl;
			return (1);
		}
	}
	return (0);
}

/**
 * ifstream: inputfilestream
 * open a file called numbers and link it to the stream. 
 * 
 */
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Please put parameters as follow:./sed <filename> <old words> <new words>" << std::endl;
		return (1);
	}
	std::string _fileName = argv[1];
	std::string	_oldWords = argv[2];
	std::string _newWords = argv[3];
	std::ifstream _infile;
	std::ofstream _outfile;
	int length = _fileName.length();
	int length_old = _oldWords.length();
	int length_new = _newWords.length();
	if (length == 0)
	{
		std::cout << "Empty file name does not count. Please put the correct file name and parameters as follow:./sed <filename> <old words> <new words>" << std::endl;
		return(1);
	}
	if (length_old == 0)
	{
		std::cout << "You have put no words to be changed. Please put parameters as follow:./sed <filename> <old words> <new words> " << std::endl;
		return(1);		
	}
	if (isDirectory(argv[1]))
		return (1);
	_infile.open(_fileName);
	if (_infile.fail())
	{
		std::cout << "Can't open the infile: " << _fileName << std::endl;
		return (1);
	}
	if (_infile.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "file is empty: " << _fileName << std::endl;
		return (1);
	}
	std::string _newFileName = _fileName;
	_newFileName += ".replace";
	_outfile.open(_newFileName);
	if (_outfile.fail())
	{
		std::cout << "Can't open the outfile: " << _newFileName << std::endl;
		return (1);
	}
	std::string content;
	while(_infile.is_open() && _outfile.is_open() && !_infile.eof())
	{
		std::size_t found = 0;
		std::getline(_infile, content);
		while (42)
		{
			found = content.find(_oldWords, found);
			if (found == std::string::npos)
				break;
			content.erase(found, length_old);
			content.insert(found, _newWords);
			found += length_new;
		}
		_outfile << content;
		if (_infile.eof())
			break;
		_outfile << std::endl;
	}
	_infile.close();
	_outfile.close();
	return (0);
}
