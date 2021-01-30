#pragma once

#include <spdlog/spdlog.h>

#define CLASSNAME(Cls) #Cls

class Logger
{
public:
    static std::shared_ptr<spdlog::logger> CreateLogger(const std::string &name) noexcept;

private:
};
