#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main() {

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n--- Array Test ---" << std::endl;
    Animal* animals[4];
    for (int k = 0; k < 2; k++) animals[k] = new Dog();
    for (int k = 2; k < 4; k++) animals[k] = new Cat();
    for (int k = 0; k < 4; k++) delete animals[k];

    return 0;
}
