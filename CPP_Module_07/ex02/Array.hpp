#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		unsigned int	_size;
		T				*array;

	public:
		Array()
			:_size(0), array(0)
		{
		};

		Array(unsigned int n)
			:_size(n), array(new T[n])
		{
		};

		Array(Array& copy)
			:_size(0), array(0)
		{
			*this = copy;
		}

		Array& operator=(Array& copy)
		{
			if (this != &copy)
			{
				if (array != 0)
					delete []array;

				unsigned int _size = copy.size();

				array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
				{
					array[i] = copy.array[i];
				}
			}
			return (*this);
		}

		T& operator[](int i)
		{
			if (i < 0 || static_cast<unsigned int>(i) >= _size)
				throw (indexException());
			return (array[i]);
		}

		const T& operator[](int i) const
		{
			if (i < 0 || static_cast<unsigned int>(i) >= _size)
				throw (indexException());
			return (array[i]);
		}

		virtual ~Array()
		{
			if (array != 0)
				delete []array;
		}

		unsigned int size() const
		{
			return (_size);
		}

		class indexException : public std::exception {
			public:
				const char*	what() const throw()
				{
					return ("Wrong index ");
				};
		};
};

#endif
