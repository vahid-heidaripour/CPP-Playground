#include "RoundRobin.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class Process final
{
public:
    Process(string_view name) : mName(name) {}

    void doWorkDuringTimeSlice() {
        cout << "Process " << mName
             << " performing work during time slice." << endl;
    }

    bool operator==(const Process& rhs) {
        return mName == rhs.mName;
    }

private:
    string mName;
};

class Scheduler final
{
public:
    Scheduler(const vector<Process>& processes);

    void scheduleTimeSlice();

    void removeProcess(const Process& process);

private:
    RoundRobin<Process> mProcesses;
};

Scheduler::Scheduler(const vector<Process>& processes)
{
    for (auto& process : processes) {
        mProcesses.add(process);
    }
}

void Scheduler::scheduleTimeSlice()
{
    try {
        mProcesses.getNext().doWorkDuringTimeSlice();
    } catch (const out_of_range&) {
        cerr << "No more processes to schedule." << endl;
    }
}

void Scheduler::removeProcess(const Process& process)
{
    mProcesses.remove(process);
}

int main()
{
    vector<Process> processes = { Process("1"), Process("2"), Process("3") };

    Scheduler scheduler(processes);
    for (int i = 0; i < 4; ++i) {
        scheduler.scheduleTimeSlice();
    }

    scheduler.removeProcess(processes[1]);
    cout << "Removed second process" << endl;

    for (int i = 0; i < 4; ++i) {
        scheduler.scheduleTimeSlice();
    }

    return 0;
}