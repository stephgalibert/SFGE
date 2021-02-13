#pragma once

#include <string>

namespace sfge
{
    struct ILogger {
        virtual ~ILogger() = default;

        virtual bool create(const std::string &category) = 0;
        virtual bool addLoggingFile(const std::string &filename) = 0;
        virtual std::string getCategory() const = 0;

        virtual void trace(const std::string &msg) const = 0;
        virtual void debug(const std::string &msg) const = 0;
        virtual void info(const std::string &msg) const = 0;
        virtual void warning(const std::string &msg) const = 0;
        virtual void error(const std::string &msg) const = 0;
    };
}// namespace sfge