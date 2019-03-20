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

}

void keep_awake_all_night()
{

}

void set_the_alarm_and_take_nap()
{

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