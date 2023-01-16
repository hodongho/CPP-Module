#include "iter.hpp"

class Test {
	private:
		int i;

	public:
		Test(): i(1234) {};
		const int& getI() const {return i;}
		~Test() {};
};

std::ostream& operator<<(std::ostream& out, Test& t)
{
	out << t.getI();
	return (out);
}

template <typename T>
void	print(T const& print)
{
	std::cout << print << std::endl;
}

int main()
{
	int			i[4] = {1, 42, 3, 5};
	std::string	str[3] = {"Hello", "World", "~"};
	Test		t[3];

	iter(i, sizeof(i) / sizeof(int), print);
	iter(str, sizeof(str) / sizeof(std::string), print);
	iter(t, sizeof(t) / sizeof(Test), print);
	return (0);
}
