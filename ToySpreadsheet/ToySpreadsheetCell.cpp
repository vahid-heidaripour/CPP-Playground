#include "ToySpreadsheetCell.h"
#include <stdexcept>

using namespace std;

ToySpreadsheetCell::ToySpreadsheetCell(double initialValue)
    : mValue(initialValue)
{
}

ToySpreadsheetCell::ToySpreadsheetCell(string_view initialValue)
    : mValue(stringToDouble(initialValue))
{
}

void ToySpreadsheetCell::set(double inValue)
{
    mValue = inValue;
}

void ToySpreadsheetCell::set(std::string_view inString)
{
    mValue = stringToDouble(inString);
}

std::string ToySpreadsheetCell::doubleToString(double inValue)
{
    return to_string(inValue);
}

double ToySpreadsheetCell::stringToDouble(std::string_view inString)
{
    return strtod(inString.data(), nullptr);
}

ToySpreadsheetCell& ToySpreadsheetCell::operator+=(const ToySpreadsheetCell &rhs)
{
    set(getValue() + rhs.getValue());
    return *this;
}

ToySpreadsheetCell& ToySpreadsheetCell::operator-=(const ToySpreadsheetCell &rhs)
{
    set(getValue() - rhs.getValue());
    return *this;
}

ToySpreadsheetCell& ToySpreadsheetCell::operator*=(const ToySpreadsheetCell &rhs)
{
    set(getValue() * rhs.getValue());
    return *this;
}

ToySpreadsheetCell& ToySpreadsheetCell::operator/=(const ToySpreadsheetCell &rhs)
{
    if (rhs.getValue() == 0) {
        throw invalid_argument("Divided by zero");
    }
    set(getValue() / rhs.getValue());
    return *this;
}

ToySpreadsheetCell operator+(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return ToySpreadsheetCell(lhs.getValue() + rhs.getValue());
}

ToySpreadsheetCell operator-(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return ToySpreadsheetCell(lhs.getValue() - rhs.getValue());
}

ToySpreadsheetCell operator*(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return ToySpreadsheetCell(lhs.getValue() * rhs.getValue());
}

ToySpreadsheetCell operator/(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    if (rhs.getValue() == 0) {
        throw invalid_argument("Divided by zero");
    }
    return ToySpreadsheetCell(lhs.getValue() + rhs.getValue());
}

bool operator==(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() == rhs.getValue());
}

bool operator!=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() != rhs.getValue());
}

bool operator<(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() < rhs.getValue());
}

bool operator>(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() > rhs.getValue());
}

bool operator<=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() <= rhs.getValue());
}

bool operator>=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() >= rhs.getValue());
}