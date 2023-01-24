#include "Span.hpp"

Span::Span()
	:maxSize(0)
{
}

Span::Span(unsigned int n)
	:maxSize(n)
{
}

Span::Span(const Span& copy)
	:maxSize(0)
{
	*this = copy;
}

Span&	Span::operator=(const Span& copy)
{
	if(this != &copy)
	{
		store = copy.getStore();
		maxSize = copy.getMaxSize();
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
	store.push_back(i);
}

unsigned int	Span::shortestSpan()
{
	if (store.size() < 2)
		throw(spanException());

	unsigned int				shortest = longestSpan();
	std::vector<int>			sortStore = store;

	sort(sortStore.begin(), sortStore.end());

	for (size_t i = 1; i != sortStore.size(); i++)
	{
		if (shortest > static_cast<unsigned int>(sortStore[i] - sortStore[i - 1]))
			shortest = static_cast<unsigned int>(sortStore[i] - sortStore[i - 1]);
	}

	return (shortest);
}

unsigned int	Span::longestSpan()
{
	if (store.size() < 2)
		throw(spanException());

	unsigned int		longest = 0;
	std::vector<int>	sortStore = store;

	sort(sortStore.begin(), sortStore.end());

	longest = *(--sortStore.end()) - *sortStore.begin();
	return (longest);
}

std::vector<int>	Span::getStore() const
{
	return (store);
}

unsigned int	Span::getMaxSize() const
{
	return (maxSize);
}

const char* Span::sizeException::what() const throw()
{
	return ("Can't add more number!");
}

const char* Span::spanException::what() const throw()
{
	return ("Don't have enough number!");
}
