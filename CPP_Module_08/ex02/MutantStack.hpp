#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack() {}
		MutantStack(MutantStack& copy) {*this = copy;}

		MutantStack& operator=(MutantStack& copy)
		{
			*this = copy;
			return (*this);
		}

		~MutantStack() {}

};

#endif
