#pragma once

#include <string>

struct ILogger {
    virtual ~ILogger() = default;

    virtual void trace(const std::string &msg) const = 0;
    virtual void debug(const std::string &msg) const = 0;
    virtual void info(const std::string &msg) const = 0;
    virtual void warning(const std::string &msg) const = 0;
    virtual void error(const std::string &msg) const = 0;
};