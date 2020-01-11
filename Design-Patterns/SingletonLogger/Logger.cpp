#include "Logger.h"
#include <stdexcept>

using namespace std;

const char* const Logger::kLogfileName = "log.txt";

Logger& Logger::instance()
{
    static Logger instance;
    return instance;
}

Logger::Logger()
{
    mOutputStream.open(kLogfileName, ios_base::app);
    if (!mOutputStream.good()) {
        throw runtime_error("Unable to initialize the logger!");
    }
}

Logger::~Logger()
{
    mOutputStream << "Logger shutting down." << endl;
    mOutputStream.close();
}

void Logger::setLogLevel(LogLevel level)
{
    mLogLevel = level;
}

string_view Logger::getLogLevelString(Logger::LogLevel level) const
{
    switch (level) {
        case LogLevel::Error:
            return "ERROR";
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Info:
            return "INFO";
    }
    throw runtime_error("Invalid log level!");
}

void Logger::log(std::string_view message, LogLevel logLevel)
{
    if (mLogLevel < logLevel) {
        return;
    }

    mOutputStream << getLogLevelString(logLevel).data() << ": " << message << endl;
}

void Logger::log(const std::vector<std::string> &message, LogLevel logLevel)
{
    if (mLogLevel < logLevel) {
        return;
    }

    for (const auto& msg : message) {
        log(msg, logLevel);
    }
}