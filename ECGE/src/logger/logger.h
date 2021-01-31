#pragma once

#include "ilogger.h"

#include <map>
#include <memory>
#include <unordered_map>

namespace ecge
{
    class Logger
    {
    public:
        static std::shared_ptr<ILogger> CreateLogger(const std::string &category);
        static bool RemoveLogger(const std::string &category);

        static bool AddLoggingFile(const std::string &category, const std::string &filename);

        static std::shared_ptr<ILogger> GetLogger(const std::string &category);

    private:
        inline static auto &getLoggers()
        {
            static std::unordered_map<std::string, std::shared_ptr<ILogger>> loggers;
            return loggers;
        }
    };
}// namespace ecge
