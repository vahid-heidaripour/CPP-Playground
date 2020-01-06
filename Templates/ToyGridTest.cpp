#include "ToyGrid.h"
#include <vector>

using namespace std;

void processIntGrid(ToyGrid<int>& /*grid*/)
{
    // body omitted for brevity
}

int main()
{
    ToyGrid<int> myIntGrid; // declares a grid that stores ints,
    // using default arguments for the constructor
    ToyGrid<double> myDoubleGrid(11, 11); // declares an 11x11 Grid of doubles

    myIntGrid.at(0, 0) = 10;
    int x = myIntGrid.at(0, 0).value_or(0);

    ToyGrid<int> grid2(myIntGrid);  // Copy constructor
    ToyGrid<int> anotherIntGrid;
    anotherIntGrid = grid2;      // Assignment operator

    processIntGrid(myIntGrid);

    ToyGrid<vector<int>> gridOfVectors;
    vector<int> myVector{ 1, 2, 3, 4 };
    gridOfVectors.at(5, 6) = myVector;

    return 0;
}
