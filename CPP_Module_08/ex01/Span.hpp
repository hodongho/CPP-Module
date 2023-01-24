#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>

class Span {
	private:
		std::vector<int>	store;
		unsigned int		maxSize;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);

		Span&	operator=(const Span& copy);

		~Span();

		void			addNumber(int i);
		template <typename T>
		void			addNumber(T begin, T end)
		{
			for (T i = begin; i != end; i++)
				addNumber(*i);
		}
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		std::vector<int>	getStore() const;
		unsigned int		getMaxSize() const;

		class sizeException : public std::exception {
			const char* what() const throw();
		};

		class spanException : public std::exception {
			const char* what() const throw();
		};
};

#endif
