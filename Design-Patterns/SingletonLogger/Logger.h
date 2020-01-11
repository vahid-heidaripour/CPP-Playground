#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <fstream>
#include <vector>
#include <string>
#include <string_view>

class Logger final
{
public:
    enum class LogLevel {
        Error,
        Info,
        Debug
    };

    static Logger& instance();

    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;

    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;

    void setLogLevel(LogLevel level);

    void log(std::string_view message, LogLevel logLevel);

    void log(const std::vector<std::string>& message, LogLevel logLevel);

private:
    Logger();
    ~Logger();

    std::string_view getLogLevelString(LogLevel level) const;

    static const char* const kLogfileName;
    std::ofstream mOutputStream;
    LogLevel mLogLevel = LogLevel::Error;
};

#endif //_LOGGER_H_
