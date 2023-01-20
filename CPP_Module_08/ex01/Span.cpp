#include "Span.hpp"

Span::Span()
	:maxSize(0), shortest(0), longest(0)
{
}

Span::Span(unsigned int n)
	:maxSize(n), shortest(0), longest(0)
{
}

Span::Span(const Span& copy)
	:maxSize(0), shortest(0), longest(0)
{
	*this = copy;
}

Span&	Span::operator=(const Span& copy)
{
	if(this != &copy)
	{
		store = copy.getStore();
		maxSize = copy.getMaxSize();
		shortest = copy.getShortest();
		longest = copy.getLongest();
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int i)
{
	if (store.size() >= getMaxSize())
		throw(sizeException());
	std::multiset<int>::iterator	now = store.insert(i);
	if (store.size() > 1)
	{
		setShortest(now);
		setLongest(now);
	}
}

void	Span::setShortest(std::multiset<int>::iterator now)
{
	std::multiset<int>::iterator	next = now;
	std::multiset<int>::iterator	prev;
	unsigned int	newShortest;

	next++;

	if (now != store.begin())
	{
		prev = now;
		prev--;
	}

	if (now == store.begin())
	{
		newShortest = *next - *now;
	}
	else if (next == store.end())
	{
		newShortest = *now - *prev;
	}
	else
	{
		newShortest = *now - *prev < *next - *now ? *now - *prev : *next - *now;
	}

	if (getShortest() == 0)
		shortest = newShortest;
	else if (newShortest != 0 && getShortest() > newShortest)
		shortest = newShortest;
}

void	Span::setLongest(std::multiset<int>::iterator now)
{
	std::multiset<int>::iterator	next = now;

	next++;
	if (now == store.begin() || next == store.end())
	{
		longest = *(--store.end()) - *store.begin();
	}
}


unsigned int	Span::shortestSpan()
{
	if (store.size() < 2)
		throw(spanException());
	return (getShortest());
}

unsigned int	Span::longestSpan()
{
	if (store.size() < 2)
		throw(spanException());
	return (getLongest());
}

const std::multiset<int>& Span::getStore() const
{
	return (store);
}

const unsigned int& Span::getMaxSize() const
{
	return (maxSize);
}

const unsigned int& Span::getShortest() const
{
	return (shortest);
}

const unsigned int& Span::getLongest() const
{
	return (longest);
}

const char* Span::sizeException::what() const throw()
{
	return ("Can't add more number!");
}

const char* Span::spanException::what() const throw()
{
	return ("Don't have enough number!");
}
