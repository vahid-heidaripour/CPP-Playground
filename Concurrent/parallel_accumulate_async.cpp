#include <iostream>
#include <vector>
#include <future>
#include <numeric>
#include <iterator>

const int MIN_ELEMENT_COUNT = 1000;

template <typename iterator>
int parallel_accumulate(iterator begin, iterator end)
{
    long length = std::distance(begin, end);

    if (length <= MIN_ELEMENT_COUNT)
    {
        std::cout << std::this_thread::get_id() << std::endl;
        return std::accumulate(begin, end, 0);
    }

    iterator mid = begin;
    std::advance(mid, (length + 1) / 2);

    std::future<int> f1 = std::async(std::launch::deferred | std::launch::async,
            parallel_accumulate<iterator>, mid, end);

    auto sum = parallel_accumulate(begin, mid);
    return sum + f1.get();
}

int main(int argc, char* argv[])
{
    std::vector<int> v(10000, 1);
    std::cout << "The sum is " << parallel_accumulate(v.begin(), v.end()) << std::endl;

    return 0;
}