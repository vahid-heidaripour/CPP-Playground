#include <iostream>
#include <mutex>
#include <list>
#include <thread>

std::list<int> my_list;
std::mutex m;

void add_to_list(int const &x)
{
    m.lock();
    my_list.push_front(x);
    m.unlock();
}

void size()
{
    m.lock();
    int size = my_list.size();
    m.unlock();
    std::cout << "size of the list is : " << size << std::endl;
}

int main(int argc, char* argv[])
{


    return 0;
}