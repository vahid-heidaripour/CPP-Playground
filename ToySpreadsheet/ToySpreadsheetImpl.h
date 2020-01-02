#ifndef _TOYSPREADSHEETIMPL_H
#define _TOYSPREADSHEETIMPL_H

#include <cstddef>
#include "ToySpreadsheet.h"
#include "ToySpreadsheetCell.h"

class ToySpreadsheet::Impl
{
public:
    Impl(const ToySpreadsheetApplication& theApp, size_t width, size_t height);
    Impl(const Impl& src);
    ~Impl();
    Impl& operator=(const Impl& rhs);

    void setCellAt(size_t x, size_t y, const ToySpreadsheetCell& cell);
    ToySpreadsheetCell& getCellAt(size_t x, size_t y);

    size_t getId() const;

private:
    void verifyCoordinate(size_t x, size_t y) const;
    void swap(Impl& other) noexcept ;

    size_t mId = 0;
    size_t mWidth = 0;
    size_t mHeight = 0;
    ToySpreadsheetCell** mCells = nullptr;

    const ToySpreadsheetApplication& mTheApp;

    static size_t sCounter;
};

#endif //_TOYSPREADSHEETIMPL_H
