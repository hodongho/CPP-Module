#include "PmergeMe.hpp"


template<typename T>
void	PmergeMe::printContainer(const T& container)
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << CYN << container[i] << " ";
	std::cout << ORI << std::endl;
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		this->vec = copy.vec;
		this->deque = copy.deque;
		this->insert_sort_size = copy.insert_sort_size;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
}

void	PmergeMe::run(int argc, char *argv[])
{
	struct timespec	tv;
	double			start, end, vec_time, deque_time;

	this->initContainer(argc, argv);
	this->setInsertSortSize();

	std::cout << GRN << "Before: ";
	this->printContainer(this->vec);

	// vector
	if (clock_gettime(CLOCK_REALTIME, &tv) == -1)
		printError();
	start = (double)tv.tv_sec * (double)1000000000 + (double)tv.tv_nsec;

	this->mergeInsertSort(this->vec, 0, this->vec.size() - 1);

	if (clock_gettime(CLOCK_REALTIME, &tv) == -1)
		printError();
	end = (double)tv.tv_sec * (double)1000000000 + (double)tv.tv_nsec;;

	vec_time = (end - start) / 1000;

	std::cout << RED << "deque------" << std::endl;

	//deque
	if (clock_gettime(CLOCK_REALTIME, &tv) == -1)
		printError();
	start = (double)tv.tv_sec * (double)1000000000 + (double)tv.tv_nsec;;

	this->mergeInsertSort(this->deque, 0, this->deque.size() - 1);

	if (clock_gettime(CLOCK_REALTIME, &tv) == -1)
		printError();
	end = (double)tv.tv_sec * (double)1000000000 + (double)tv.tv_nsec;;

	deque_time = (end - start) / 1000;

	std::cout << GRN << "After:  ";
	this->printContainer(this->vec);
	this->printContainer(this->deque);

	this->printAlgorithmExecTime(vec_time, deque_time);
	this->isSorted();
}

void	PmergeMe::initContainer(int argc, char *argv[])
{
	int	value;

	for (int index = 1; index < argc; index++)
	{
		value = atoi(argv[index]);
		if (this->validateValue(value, argv[index]) == false)
			printError();
		this->vec.push_back(value);
		this->deque.push_back(value);
	}
}

bool	PmergeMe::validateValue(int value, std::string origin)
{
	if (value <= 0)
		return (false);

	for (size_t	index = 0; index < origin.size(); index++)
	{
		if (isdigit(origin[index]) == 0)
			return (false);
	}

	return (true);
}

void	PmergeMe::setInsertSortSize(void)
{
	size_t new_size = sqrt(this->vec.size());

	if (new_size > 3)
		this->insert_sort_size = new_size;
	else
		this->insert_sort_size = 3;
}

template <typename T>
void	PmergeMe::mergeInsertSort(T& container, size_t start, size_t end)
{
	if (end - start <= this->insert_sort_size)
	{
		this->insertSort(container, start, end);
		return ;
	}

	size_t	mid = (start + end) / 2;

	this->mergeInsertSort(container, start, mid);
	this->mergeInsertSort(container, mid + 1, end);
	this->merge(container, start, mid, end);
}

template <typename T>
void	PmergeMe::insertSort(T& container, size_t start, size_t end)
{
	typename T::iterator	iter = container.begin() + start + 1;
	typename T::iterator	end_iter = container.begin() + end + 1;
	typename T::iterator	loop_iter;

	for (; iter != end_iter; iter++)
	{
		loop_iter = container.begin() + start;

		for (; loop_iter != iter; loop_iter++)
		{
			if (*loop_iter > *iter)
			{
				unsigned int	value = *iter;

				printContainer(container);
				std::cout << BRW << *loop_iter << " " << *iter << " " << value << std::endl;

				iter = container.erase(iter);

				printContainer(container);
				std::cout << BRW << *loop_iter << " " << *iter << " " << value << std::endl;

				container.insert(loop_iter, value);

				printContainer(container);
				std::cout << BRW << *loop_iter << " " << *iter << " " << value << std::endl;

				break ;
			}
		}
	}
}

template <typename T>
void	PmergeMe::merge(T& container, size_t start, size_t mid, size_t end)
{
	T						tmp_container;
	typename T::iterator	left_iter = container.begin() + start;
	typename T::iterator	left_end_iter = container.begin() + mid + 1;
	typename T::iterator	right_iter = container.begin() + mid + 1;
	typename T::iterator	right_end_iter = container.begin() + end + 1;

	while (left_iter != left_end_iter && right_iter != right_end_iter)
	{
		if (*left_iter <= *right_iter)
		{
			tmp_container.push_back(*left_iter);
			left_iter++;
		}
		else
		{
			tmp_container.push_back(*right_iter);
			right_iter++;
		}
	}

	while (left_iter != left_end_iter)
	{
		tmp_container.push_back(*left_iter);
		left_iter++;
	}

	while (right_iter != right_end_iter)
	{
		tmp_container.push_back(*right_iter);
		right_iter++;
	}

	size_t index = 0;

	for (; start != end + 1; start++)
	{
		container[start] = tmp_container[index];
		index++;
	}
}

void	PmergeMe::printAlgorithmExecTime(const double& vec_time, const double& deque_time)
{
	std::cout 	<< PUP;
	std::cout	<< "Time to process a range of " << this->vec.size()
				<< " elements with std::vector : " << vec_time << " us" << std::endl;

	std::cout	<< "Time to process a range of " << this->deque.size()
				<< " elements with std::deque  : " << deque_time << " us" << std::endl;
	std::cout 	<< ORI;
}

void	PmergeMe::isSorted(void)
{
	std::deque<unsigned int>::iterator	iter = this->deque.begin() + 1;
	std::deque<unsigned int>::iterator	end_iter = this->deque.end();

	for(; iter != end_iter; iter++)
	{
		if (*(iter - 1) > *iter)
			printError();
	}

	// std::deque<unsigned int> tmp_deque(this->vec.begin(), this->vec.end());
	// if (this->deque != tmp_deque)
	// 	printError();
}

void	printError(void)
{
	std::cout << RED << "Error" << std::endl;
	exit(1);
}
