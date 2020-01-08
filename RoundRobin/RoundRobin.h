#ifndef _ROUNDROBIN_H_
#define _ROUNDROBIN_H_

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class RoundRobin
{
public:
    RoundRobin(size_t numExpected = 0);
    virtual ~RoundRobin() = default;

    RoundRobin(const RoundRobin& src) = delete;
    RoundRobin& operator=(const RoundRobin& rhs) = delete;

    RoundRobin(RoundRobin&& src) = default;
    RoundRobin& operator=(RoundRobin&& rhs) = default;

    void add(const T& element);

    void remove(const T& element);

    T& getNext();

private:
    std::vector<T> mElements;
    typename std::vector<T>::iterator mCurrentElement;
};

template <typename T>
RoundRobin<T>::RoundRobin(size_t numExpected)
{
    mElements.reserve(numExpected);
    mCurrentElement = begin(mElements);
}

template <typename T>
void RoundRobin<T>::add(const T& element)
{
    int pos = mCurrentElement - begin(mElements);
    mElements.push_back(element);
    mCurrentElement = begin(mElements) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& element)
{
    for (auto it = begin(mElements); it != end(mElements); ++it) {
        if (*it == element) {
            int newPos;

            if (mCurrentElement == end(mElements) - 1 &&
                mCurrentElement == it) {
                newPos = 0;
            } else if (mCurrentElement <= it) {
                newPos = mCurrentElement - begin(mElements);
            } else {
                newPos = mCurrentElement - begin(mElements) - 1;
            }

            mElements.erase(it);
            mCurrentElement = begin(mElements) + newPos;

            return;
        }
    }
}

template <typename T>
T& RoundRobin<T>::getNext()
{
    if (mElements.empty()) {
        throw std::out_of_range("No elements in the list");
    }

    auto& toReturn = *mCurrentElement;

    ++mCurrentElement;
    if (mCurrentElement == end(mElements)) {
        mCurrentElement = begin(mElements);
    }

    return toReturn;
}

#endif //_ROUNDROBIN_H_
