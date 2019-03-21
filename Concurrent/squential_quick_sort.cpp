#include <iostream>
#include <algorithm>
#include <list>

template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input)
{
    if (input.size() < 2)
    {
        return input;
    }

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());
    T pivot = *result.begin();

    auto divide_point = std::partition(input.begin(), input.end(), [&](T const & t)
    {
        return t < pivot;
    });

    std::list<T> lower_list;
    lower_list.splice(lower_list.end(), input, input.begin(), divide_point);

    auto new_lower(sequential_quick_sort(std::move(lower_list)));
    auto new_upper(sequential_quick_sort(std::move(input)));

    result.splice(result.begin(), new_lower);
    result.splice(result.end(), new_upper);

    return result;
}

