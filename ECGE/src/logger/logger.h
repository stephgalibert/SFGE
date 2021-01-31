#pragma once

#include "ilogger.h"

#include <map>
#include <memory>
#include <unordered_map>

namespace ecge
{
    class Logger
    {
    private:
        static auto &getLoggers();

    public:
        static std::shared_ptr<ILogger> CreateLogger(const std::string &category);
        static bool RemoveLogger(const std::string &category);

        static bool AddLoggingFile(const std::string &category, const std::string &filename);

        static std::shared_ptr<ILogger> GetLogger(const std::string &category);
    };
}// namespace ecge
