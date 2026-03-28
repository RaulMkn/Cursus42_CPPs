#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main() {
    std::cout << "--- Simple Initialization Test ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n--- Array of Animals Test ---" << std::endl;
    Animal* animals[10];
    for (int k = 0; k < 5; k++) animals[k] = new Dog();
    for (int k = 5; k < 10; k++) animals[k] = new Cat();
    
    for (int k = 0; k < 10; k++) delete animals[k];

    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    
    return 0;
}
