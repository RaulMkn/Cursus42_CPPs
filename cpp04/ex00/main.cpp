#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- Standard Animal Tests ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\nSounds:" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\nCleaning up standard animals:" << std::endl;
    delete meta;
    delete j;
    delete i;


    std::cout << "\n\n--- Wrong Animal Tests ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    
    std::cout << "\nTypes:" << std::endl;
    std::cout << wrongI->getType() << " " << std::endl;

    std::cout << "\nSounds:" << std::endl;
    wrongI->makeSound(); 
    wrongMeta->makeSound();

    std::cout << "\nCleaning up wrong animals:" << std::endl;
    delete wrongMeta;
    delete wrongI;

    return 0;
}
