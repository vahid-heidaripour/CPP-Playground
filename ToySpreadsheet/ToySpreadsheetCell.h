#ifndef _TOYSPREADSHEETCELL_H_
#define _TOYSPREADSHEETCELL_H_

#include <cstddef>
#include <string>
#include <string_view>

class ToySpreadsheetCell
{
public:
    ToySpreadsheetCell() = default;
    ToySpreadsheetCell(double initialValue);
    explicit ToySpreadsheetCell(std::string_view initialValue);

    void set(double inValue);
    void set(std::string_view inString);

    double getValue() const { mNumAccesses++; return mValue; };
    std::string getString() const { mNumAccesses++; return doubleToString(mValue); };

    static std::string doubleToString(double inValue);
    static double stringToDouble(std::string_view inString);

    ToySpreadsheetCell& operator+=(const ToySpreadsheetCell& rhs);
    ToySpreadsheetCell& operator-=(const ToySpreadsheetCell& rhs);
    ToySpreadsheetCell& operator*=(const ToySpreadsheetCell& rhs);
    ToySpreadsheetCell& operator/=(const ToySpreadsheetCell& rhs);

private:
    double mValue = 0;
    mutable size_t mNumAccesses = 0;
};

ToySpreadsheetCell operator+(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
ToySpreadsheetCell operator-(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
ToySpreadsheetCell operator*(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
ToySpreadsheetCell operator/(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
bool operator==(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
bool operator>=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
bool operator<=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
bool operator!=(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
bool operator>(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);
bool operator<(const ToySpreadsheetCell& lhs, const ToySpreadsheetCell& rhs);

#endif //_TOYSPREADSHEETCELL_H_
