#include <iostream>
#include <fstream>

std::string	read_file(char *argv[])
{
	std::string		contents = 0;
	std::string		tmp = 0;
	std::ifstream	file(argv[1]);

	if (file.fail())
	{
		std::cerr << "File doesn't exist!" << std::endl;
		exit(1);
	}
	while (true)
	{
		getline(file, tmp);
		contents += tmp;
		if(file.eof())
			break ;
	}
	return (contents);
}

std::string	replace(std::string contents, std::string s1, std::string s2)
{
	std::string	result;
	size_t		start = 0;
	size_t		end = 0;

	while (true)
	{
		end = contents.find(s1, start);
		if (end == std::string::npos)
			return ;
		result += contents.substr(start, end) + s2;
		start += end + s1.length();
		end = start;
	}
	return (result);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Wrong arguments!" << std::endl;
		return (1);
	}

	std::string contents;

	contents = read_file(argv);
	contents = replace(contents, argv[2], argv[3]);
	return(0);
}
