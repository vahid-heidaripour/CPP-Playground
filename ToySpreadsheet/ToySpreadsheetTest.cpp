#include "ToySpreadsheet.h"

using namespace std;

class ToySpreadsheetApplication {};

int main()
{
    ToySpreadsheetApplication theApp;
    ToySpreadsheet s1(theApp);
    ToySpreadsheet s3(theApp, 5, 6);
    ToySpreadsheet s4(s3);
    s1 = s4;

    return 0;
}
