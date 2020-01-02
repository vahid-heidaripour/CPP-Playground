#include <iostream>
#include "Toy.h"

void Toy::handleMessage(std::string &message)
{
    //helper(message); //the helper function needs a rvalue reference, this causes a compilation error
    helper(std::move(message));
}

void Toy::handleMessage(std::string &&message)
{
    helper(std::move(message));
}

void Toy::helper(std::string &&message)
{
    std::cout << "This is the message: " << message << std::endl;
}