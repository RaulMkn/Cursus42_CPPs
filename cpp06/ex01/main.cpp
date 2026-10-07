#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data		original;
	original.id = 42;
	original.name = "Bureaucrat";
	original.value = 3.14;

	uintptr_t	raw = Serializer::serialize(&original);
	Data		*restored = Serializer::deserialize(raw);

	std::cout << "Original address:  " << &original << std::endl;
	std::cout << "Serialized value:  " << raw << std::endl;
	std::cout << "Restored address:  " << restored << std::endl;
	std::cout << std::endl;
	std::cout << "Same pointer?      " << (restored == &original ? "yes" : "no") << std::endl;
	std::cout << std::endl;
	std::cout << "id:    " << restored->id << std::endl;
	std::cout << "name:  " << restored->name << std::endl;
	std::cout << "value: " << restored->value << std::endl;
	return (0);
}
