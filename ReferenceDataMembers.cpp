class ToyClass
{
public:
    ToyClass(int& ref) : mRef(ref)
    {
    }

private:
    int& mRef; // you must initialize reference data members in the constructor initializer,
    // not in the body of the constructor.
};

int main()
{
    int i = 123;
    ToyClass t(i);

    return 0;
}
