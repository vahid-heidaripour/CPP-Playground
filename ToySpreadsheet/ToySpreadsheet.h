#ifndef _TOYSPREADSHEET_H_
#define _TOYSPREADSHEET_H_

#include <memory>
#include "ToySpreadsheetCell.h"

class ToySpreadsheetApplication;

class ToySpreadsheet
{
public:
    ToySpreadsheet(const ToySpreadsheetApplication& theApp, size_t width = kMaxWidth, size_t height = kMaxHeight);
    ToySpreadsheet(const ToySpreadsheet& src);
    ~ToySpreadsheet();

    ToySpreadsheet& operator=(const ToySpreadsheet& rhs);

    void setCellAt(size_t x, size_t y, const ToySpreadsheetCell& cell);
    ToySpreadsheetCell& getCellAt(size_t x, size_t y);

    size_t getId() const;

    static const size_t kMaxWidth = 100;
    static const size_t kMaxHeight = 100;

    friend void swap(ToySpreadsheet& first, ToySpreadsheet& second) noexcept;

private:
    class Impl;
    std::unique_ptr<Impl> mImpl;
};

#endif //_TOYSPREADSHEET_H_
