#include "PmergeMe_list_ver.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
		printError();

	PmergeMe	PmergeMe;

	PmergeMe.run(argc, argv);

	return (0);
}
