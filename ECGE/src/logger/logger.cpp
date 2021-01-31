#include "ecge/logger/logger.h"
#include "ecge/logger/ilogger.h"

#include "spdloglogger.h"

namespace ecge
{
    auto &Logger::getLoggers()
    {
        static std::unordered_map<std::string, std::shared_ptr<ILogger>> loggers;
        return loggers;
    }

    std::shared_ptr<ILogger> Logger::CreateLogger(const std::string &category)
    {
        auto logger = std::make_shared<SpdlogLogger>();
        if (!logger->create(category))
            return nullptr;

        std::unordered_map<std::string, std::shared_ptr<ILogger>> &loggers = getLoggers();
        const auto [iterator, success] = loggers.insert({category, logger});
        return iterator->second;
    }

    bool Logger::RemoveLogger(const std::string &category)
    {
        std::unordered_map<std::string, std::shared_ptr<ILogger>> &loggers = getLoggers();
        return static_cast<bool>(loggers.erase(category));
    }

    bool Logger::AddLoggingFile(const std::string &category, const std::string &filename)
    {
        std::shared_ptr<ILogger> logger = GetLogger(category);
        if (!logger)
            return false;
        return logger->addLoggingFile(filename);
    }

    std::shared_ptr<ILogger> Logger::GetLogger(const std::string &category)
    {
        std::unordered_map<std::string, std::shared_ptr<ILogger>> &loggers = getLoggers();
        auto it = loggers.find(category);

        if (it != loggers.end())
            return it->second;
        return nullptr;
    }
}// namespace ecge
