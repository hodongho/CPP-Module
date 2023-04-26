#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <time.h>

# define ORI "\e[0;m"
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
		std::deque<unsigned int>	deque;
		size_t						insert_sort_size;

		void	initContainer(int argc, char *argv[]);
		bool	validateValue(int value, std::string origin);
		void	setInsertSortSize(void);

		template <typename T>
		void	mergeInsertSort(T& container, size_t start, size_t end);
		template <typename T>
		void	insertSort(T& container, size_t start, size_t end);
		template <typename T>
		void	merge(T& container, size_t start, size_t mid, size_t end);

		void	printAlgorithmExecTime(const double& vec_time, const double& deque_time);
		template<typename T>
		void	printContainer(const T& container);

		void	isSorted(void);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& copy);

		PmergeMe&	operator=(const PmergeMe& copy);

		~PmergeMe(void);

		void	run(int argc, char *argv[]);
};

void	printError(void);

#endif
