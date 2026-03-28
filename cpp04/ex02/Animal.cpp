#include "Animal.hpp"
Animal::Animal() : type("Animal") { std::cout << "Animal default constructor" << std::endl; }
Animal::Animal(const Animal& other) { std::cout << "Animal copy constructor" << std::endl; *this = other; }
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment" << std::endl;
    if (this != &other) this->type = other.type;
    return *this;
}
Animal::~Animal() { std::cout << "Animal destructor" << std::endl; }
std::string Animal::getType() const { return this->type; }
