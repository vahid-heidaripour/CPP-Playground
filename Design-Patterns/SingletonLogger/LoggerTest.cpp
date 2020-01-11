#include "Logger.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
    Logger::instance().setLogLevel(Logger::LogLevel::Debug);

    Logger::instance().log("test message", Logger::LogLevel::Debug);
    vector<string> items = { "item1", "item2" };
    Logger::instance().log(items, Logger::LogLevel::Error);

    Logger::instance().setLogLevel(Logger::LogLevel::Error);
    Logger::instance().log("A debug message", Logger::LogLevel::Debug);

    return 0;
}