#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
		printError();

	PmergeMe	PmergeMe;

	PmergeMe.run(argc, argv);

	return (0);
}
