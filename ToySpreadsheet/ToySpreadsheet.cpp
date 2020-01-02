#include "ToySpreadsheet.h"
#include "ToySpreadsheetImpl.h"
#include <utility>

ToySpreadsheet::ToySpreadsheet(const ToySpreadsheetApplication& theApp, size_t width, size_t height)
{
    mImpl = std::make_unique<Impl>(theApp, width, height);
}

ToySpreadsheet::ToySpreadsheet(const ToySpreadsheet& src)
{
    mImpl = std::make_unique<Impl>(*src.mImpl);
}

ToySpreadsheet::~ToySpreadsheet() = default;

void ToySpreadsheet::setCellAt(size_t x, size_t y, const ToySpreadsheetCell& cell)
{
    mImpl->setCellAt(x, y, cell);
}

ToySpreadsheetCell& ToySpreadsheet::getCellAt(size_t x, size_t y)
{
    return mImpl->getCellAt(x, y);
}

size_t ToySpreadsheet::getId() const
{
    return mImpl->getId();
}

ToySpreadsheet& ToySpreadsheet::operator=(const ToySpreadsheet& rhs)
{
    *mImpl = *rhs.mImpl;
    return *this;
}

void swap(ToySpreadsheet& first, ToySpreadsheet& second) noexcept
{
    using std::swap;

    swap(first.mImpl, second.mImpl);
}
