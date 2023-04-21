#include "PmergeMe.hpp"


void	print_vec(std::vector<unsigned int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << CYN << vec[i] << " ";
	std::cout << WHI << std::endl;
}



PmergeMe::PmergeMe()
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
		this->list = copy.list;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::sort(int argc, char *argv[])
{
	this->initVec(argc, argv);
	this->mergeInsertSort();
}

void	PmergeMe::initVec(int argc, char *argv[])
{
	int	value;
	for (int index = 1; index < argc; index++)
	{
		value = atoi(argv[index]);
		if (this->validateValue(value, argv[index]) == false)
			printError();
		this->vec.push_back(value);
	}
	print_vec(this->vec);
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

void	PmergeMe::mergeInsertSort()
{
	this->setInsertSortSize();
}

void	PmergeMe::setInsertSortSize()
{
	size_t new_size = sqrt(this->vec.size());

	if (new_size > 2)
		this->insert_sort_size = new_size;
}

void	printError()
{
	std::cout << RED << "Error" << std::endl;
	exit(1);
}
