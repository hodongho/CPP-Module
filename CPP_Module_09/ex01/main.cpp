#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		printError("wrong argument!");

	RPN	rpn(argv[1]);

	rpn.calculate();

	return (0);
}
