#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
    std::cout << "WrongCat named constructor called\n";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "WrongCat assignment operator called\n";
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong pussy cat: Meow meow >:(\n";
}
