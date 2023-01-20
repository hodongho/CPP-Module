#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack() {}
		MutantStack(const MutantStack& copy) {*this = copy;}

		MutantStack& operator=(const MutantStack& copy)
		{
			*this = copy;
			return (*this);
		}

		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}
};

#endif
