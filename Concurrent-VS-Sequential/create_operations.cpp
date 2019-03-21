#include <iostream>
#include <random>
#include <fstream>

std::random_device rd;
std::default_random_engine drg(rd());

char generateRandomOperator()
{
    std::uniform_int_distribution<int> uniform_dist(1, 2);
    int coin = uniform_dist(drg);
    if (coin == 1)
        return '+';
    else
        return '#';
}

int generateRandomId(int max)
{
    std::uniform_int_distribution<int> uniform_dist(0, max);
    return uniform_dist(drg);
}

std::string generateCommand()
{
    int firstRandomId = generateRandomId(9);
    int secondRandomId = generateRandomId(9);
    char randomOperator = generateRandomOperator();

    return std::to_string(firstRandomId) +
           " " +
           std::to_string(secondRandomId) +
           " " +
           std::string(1, randomOperator);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " number_of_commands" << std::endl;
        return 1;
    }

    std::ofstream outfile;
    outfile.open("command_list");

    for (int i = 0; i < atoi(argv[1]); ++i)
        if (i != atoi(argv[1]) - 1)
            outfile << generateCommand() << std::endl;
        else
            outfile << generateCommand();

    outfile.close();

    return 0;
}
