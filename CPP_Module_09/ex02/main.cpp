#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
		printError();

	PmergeMe	sort;

	sort.sort(argc, argv);
	return (0);
}
