#ifndef _TOY_H_
#define _TOY_H_

#include <string>

class Toy
{
public:
    void handleMessage(std::string& message); //works with lvalue
    void handleMessage(std::string&& message); //works with rvalue
private:
    void helper(std::string&& message);
};

#endif //_TOY_H_
