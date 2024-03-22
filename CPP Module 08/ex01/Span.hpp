#pragma once

# include <vector>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_vec;
		Span();
	
	public:
		Span(unsigned int N);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void fillVector(unsigned int amount);

	class NoSpanFoundException : public std::exception {
		public:
			const char* what() const throw() override{
				return ("No span found.");
			};
	};
		
	class CantAddNewException : public std::exception {
		public:
			const char* what() const throw() override{
				return ("Container is already full.");
			};
	};
};