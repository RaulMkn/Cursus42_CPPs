#include "Cat.hpp"
Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor" << std::endl;
    this->brain = new Brain(*other.brain);
    *this = other;
}
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->brain) delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}
Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor" << std::endl;
}
void Cat::makeSound() const { std::cout << "Meow! Meow!" << std::endl; }
