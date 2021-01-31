#pragma once

#include "ilogger.h"

#include <memory>

// to remove
#define CLASSNAME(Cls) #Cls

namespace ecge
{
    class Logger
    {
    public:
        // static Type CreaterLoggerFile(const std::string &name, const std::string &filename);
        static std::unique_ptr<ILogger> CreateLogger(const std::string &category);

    private:
    };
}// namespace ecge
