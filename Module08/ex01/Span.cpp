#include "Span.hpp"

Span::Span(unsigned int N) : _n(N) {}

Span::Span(Span const &other) : _n(other._n), _numbers(other._numbers) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() < _n)
		_numbers.push_back(number);
	else
		throw FullSpanException();
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (unsigned int i = 2; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full, cannot add more numbers";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Span does not contain enough numbers to calculate span";
}
