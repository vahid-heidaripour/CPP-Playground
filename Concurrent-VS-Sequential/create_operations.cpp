#include <iostream>
#include <random>
#include <fstream>

std::random_device rd;
std::default_random_engine drg(rd());

std::ofstream outfile;

int generateRandomOperator()
{
    std::uniform_int_distribution<int> uniform_dist(1, 2);
    int coin = uniform_dist(drg);
    if (coin == 1)
        return 0;
    else
        return 1;
}

int generateRandomId(int max)
{
    std::uniform_int_distribution<int> uniform_dist(0, max);
    return uniform_dist(drg);
}

void generateCommand()
{
    int firstRandomId = generateRandomId(9);
    int secondRandomId = generateRandomId(9);
    int randomOperator = generateRandomOperator();

    outfile << firstRandomId << " " << secondRandomId << " " << randomOperator << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " number_of_commands" << std::endl;
        return 1;
    }

    outfile.open("command_list");

    for (int i = 0; i < atoi(argv[1]); ++i)
        generateCommand();

    outfile.close();

    return 0;
}
