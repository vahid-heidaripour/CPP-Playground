#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>
#include <condition_variable>

bool have_i_arrived = false;
int total_distance = 10;
int distance_covered = 0;
std::condition_variable cv;
std::mutex m;

void keep_moving()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        distance_covered++;

        if (distance_covered == total_distance)
            cv.notify_one();
    }
}

void ask_driver_to_wake_up()
{
    std::unique_lock<std::mutex> ul(m);
    cv.wait(ul, []{ return distance_covered == total_distance;});
    std::cout << "finally I am there, distance_covered = " << distance_covered << std::endl;
}

int main(int argc, char* argv[])
{
    std::thread driver_thread(keep_moving);
    std::thread passenger_thread(ask_driver_to_wake_up);

    passenger_thread.join();
    driver_thread.join();

    return 0;
}