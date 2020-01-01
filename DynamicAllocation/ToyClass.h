#ifndef _TOYCLASS_H_
#define _TOYCLASS_H_

class ToyClass
{
public:
    ToyClass(size_t width, size_t height);
    ~ToyClass();
    void setCellAt(size_t x, size_t y, const int& value);
    int& getCellAt(size_t x, size_t y);

private:
    void verifyCoordinate(size_t x, size_t y) const;
    size_t mWidth = 0;
    size_t mHeight = 0;
    int** cells = nullptr;
};

#endif //_TOYCLASS_H_
