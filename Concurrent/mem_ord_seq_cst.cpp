#include <iostream>
#include <atomic>
#include <memory>
#include <thread>
#include <assert.h>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x()
{
    x.store(true, std::memory_order_seq_cst);
}

void write_y()
{
    y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y()
{
    while (!x.load(std::memory_order_seq_cst));

    if (y.load(std::memory_order_seq_cst))
        z++;
}

void read_y_then_x()
{
    while (!y.load(std::memory_order_seq_cst));

    if (x.load(std::memory_order_seq_cst))
        z++;
}

int main(int argc, char* argv[])
{
    x = false;
    y = false;
    z = 0;

    std::thread thread_a(write_x);
    std::thread thread_b(write_y);
    std::thread thread_c(read_x_then_y);
    std::thread thread_d(read_y_then_x);

    thread_a.join();
    thread_b.join();
    thread_c.join();
    thread_d.join();

    assert(z != 0);

    return 0;
}