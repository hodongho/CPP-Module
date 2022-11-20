#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout
		<< "strORI : " << &str << std::endl
		<< "strPTR : " << &stringPTR << std::endl
		<< "strREF : " << &stringREF << std::endl << std::endl;

	std::cout
		<< "strORI : " << str << std::endl
		<< "strPTR : " << *stringPTR << std::endl
		<< "strREF : " << stringREF << std::endl;
	return (0);
}
