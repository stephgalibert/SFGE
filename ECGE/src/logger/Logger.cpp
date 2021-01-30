//
// Created by sgalibert on 30/01/2021.
//

#include "Logger.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <iostream>

std::shared_ptr<spdlog::logger> Logger::CreateLogger(const std::string &name) noexcept
{
    std::shared_ptr<spdlog::logger> logger = nullptr;

    try {
        auto loggerConsole = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        loggerConsole->set_level(spdlog::level::debug);

        auto loggerFile = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt", true);
        loggerFile->set_level(spdlog::level::debug);

        spdlog::sinks_init_list loggers = {loggerConsole, loggerFile};

        logger = std::make_shared<spdlog::logger>(name, loggers.begin(), loggers.end());
        logger->set_level(spdlog::level::debug);
    } catch (const spdlog::spdlog_ex &exception) {
        std::cerr << exception.what() << std::endl;
    }

    return logger;
}