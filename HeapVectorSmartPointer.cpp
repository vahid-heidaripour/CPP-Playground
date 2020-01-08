#include <vector>
#include <memory>

class Element
{
public:
    Element() {}
    virtual ~Element() = default;
};

int main()
{
    auto elementVector = std::make_unique<std::vector<Element>>(10);

    return 0;
}