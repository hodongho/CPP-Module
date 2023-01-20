#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class notFoundException : public std::exception {
	const char*	what() const throw()
	{
		return ("Not Found!");
	}
};

template <typename T>
int	easyfind(T& container, int i)
{
	typename T::iterator iter = find(container.begin(), container.end(), i);

	if(iter == container.end())
		throw (notFoundException());

	return (*iter);
}

#endif
