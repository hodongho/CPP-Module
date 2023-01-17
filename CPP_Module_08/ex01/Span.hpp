#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	private:
		std::vector<int> vec;

	public:
		Span();
		Span(unsigned int n);
		Span(Span& copy);

		Span&	operator=(Span& copy);

		~Span();

		void	addNumber(int i);
		int		shortestSpan();
		int		longestSpan();
};

#endif
