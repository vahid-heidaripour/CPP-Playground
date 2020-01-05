const int getArraySize1()
{
    return 32;
}

constexpr int getArraySize2()
{
    return 32;
}

int main()
{
    //int myArray1[getArraySize1()]; // error! expression did not evaluate to a constant

    int myArray2[getArraySize2()];
    myArray2[0] = 1;

    return 0;
}