#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>

class Span {
	private:
		std::multiset<int>	store;
		unsigned int		maxSize;
		unsigned int		shortest;
		unsigned int		longest;

	public:
		Span();
		Span(unsigned int n);
		Span(Span& copy);

		Span&	operator=(Span& copy);

		~Span();

		void			addNumber(int i);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		const std::multiset<int>&	getStore() const;
		const unsigned int&			getMaxSize() const;
		const unsigned int&			getShortest() const;
		const unsigned int&			getLongest() const;

		void	setShortest(std::multiset<int>::iterator now);
		void	setLongest(std::multiset<int>::iterator now);

		class sizeException : public std::exception {
			const char* what() const throw();
		};

		class spanException : public std::exception {
			const char* what() const throw();
		};
};

#endif
