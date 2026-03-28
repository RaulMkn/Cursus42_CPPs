#include "Dog.hpp"
Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor" << std::endl;
    this->brain = new Brain(*other.brain);
    *this = other;
}
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->brain) delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}
Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor" << std::endl;
}
void Dog::makeSound() const { std::cout << "Woof! Woof!" << std::endl; }
