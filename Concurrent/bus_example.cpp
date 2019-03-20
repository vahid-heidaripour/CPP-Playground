#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>

bool have_i_arrived = false;
int distance_my_destination = 10;
int distance_covered = 0;

bool keep_driving()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        distance_covered++;
    }

    return false;
}

void keep_awake_all_night()
{
    while (distance_covered < distance_my_destination)
    {
        std::cout << "keep check, whether I am there \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "finally I am there, distance_covered = " << distance_covered << std::endl;
}

void set_the_alarm_and_take_nap()
{
    if (distance_covered < distance_my_destination)
    {
        std::cout << "let me take a nap \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }

    std::cout << "finally I am there, distance covered = " << distance_covered << std::endl;
}

int main(int argc, char* argv[])
{
    std::thread driver_thread(keep_driving);
    std::thread keep_awake_thread(keep_awake_all_night);
    std::thread set_alarm_thread(set_the_alarm_and_take_nap);

    keep_awake_thread.join();
    set_alarm_thread.join();
    driver_thread.join();

    return 0;
}