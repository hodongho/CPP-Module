#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cmath>

# define WHI "\e[1;37m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define BRW "\e[0;33m"
# define BLU "\e[0;34m"
# define PUP "\e[0;35m"
# define CYN "\e[0;36m"

class PmergeMe {
	private:
		std::vector<unsigned int>	vec;
		std::list<unsigned int>		list;
		size_t						insert_sort_size = 2;

		void	initVec(int	argc, char *argv[]);
		bool	validateValue(int value, std::string origin);

		void	mergeInsertSort();
		void	setInsertSortSize();


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);

		PmergeMe&	operator=(const PmergeMe& copy);

		~PmergeMe();

		void	sort(int argc, char *argv[]);
};

void	printError();

#endif
