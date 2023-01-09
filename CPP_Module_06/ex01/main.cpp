#include "Serialization.hpp"

int main()
{
	Data		data = {42};
	uintptr_t	ptr = 0;
	Data		*ret;

	std::cout << "data's value: " << data.value << std::endl << std::endl;

	ptr = serialize(&data);
	std::cout << "data's address: " << &data << std::endl;
	std::cout << "ptr's value: " << ptr << std::endl << std::endl;

	ret = deserialize(ptr);
	std::cout << "data's value: " << data.value << std::endl;
	std::cout << "ret's value: " << ret->value << std::endl;

	return (0);
}
