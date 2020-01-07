#include "ToySpreadsheetCell.h"
#include <stdexcept>
#include <iostream>

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

void ToySpreadsheetCell::set(string_view inString)
{
    mValue = stringToDouble(inString);
}

string ToySpreadsheetCell::doubleToString(double inValue)
{
    return to_string(inValue);
}

double ToySpreadsheetCell::stringToDouble(string_view inString)
{
    return strtod(inString.data(), nullptr);
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
        throw invalid_argument("Divide by zero.");
    }
    return ToySpreadsheetCell(lhs.getValue() / rhs.getValue());
}

ToySpreadsheetCell& ToySpreadsheetCell::operator+=(const ToySpreadsheetCell& rhs)
{
    set(getValue() + rhs.getValue());
    return *this;
}

ToySpreadsheetCell& ToySpreadsheetCell::operator-=(const ToySpreadsheetCell& rhs)
{
    set(getValue() - rhs.getValue());
    return *this;
}

ToySpreadsheetCell& ToySpreadsheetCell::operator*=(const ToySpreadsheetCell& rhs)
{
    set(getValue() * rhs.getValue());
    return *this;
}

ToySpreadsheetCell& ToySpreadsheetCell::operator/=(const ToySpreadsheetCell& rhs)
{
    if (rhs.getValue() == 0) {
        throw invalid_argument("Divide by zero.");
    }
    set(getValue() / rhs.getValue());
    return *this;
}

bool operator==(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() == rhs.getValue());
}

bool operator<(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() < rhs.getValue());
}

bool operator>(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() > rhs.getValue());
}

bool operator!=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() != rhs.getValue());
}

bool operator<=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() <= rhs.getValue());
}

bool operator>=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs)
{
    return (lhs.getValue() >= rhs.getValue());
}

ToySpreadsheetCell ToySpreadsheetCell::operator-() const
{
    return ToySpreadsheetCell(-getValue());
}

ToySpreadsheetCell& ToySpreadsheetCell::operator++()
{
    set(getValue() + 1);
    return *this;
}

ToySpreadsheetCell ToySpreadsheetCell::operator++(int)
{
    auto oldCell(*this); // Save current value
    ++(*this);           // Increment using prefix ++
    return oldCell;      // Return the old value
}

ToySpreadsheetCell& ToySpreadsheetCell::operator--()
{
    set(getValue() - 1);
    return *this;
}

ToySpreadsheetCell ToySpreadsheetCell::operator--(int)
{
    auto oldCell(*this); // Save current value
    --(*this);           // Decrement using prefix --
    return oldCell;      // Return the old value
}

ostream& operator<<(ostream& ostr, const ToySpreadsheetCell& cell)
{
    ostr << cell.getValue();
    return ostr;
}

istream& operator>>(istream& istr, ToySpreadsheetCell& cell)
{
    double value;
    istr >> value;
    cell.set(value);
    return istr;
}
