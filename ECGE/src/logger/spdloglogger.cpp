#include "spdloglogger.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <iostream>

namespace ecge
{
    // TODO:
    // There is a problem with multiple SpdLogLogger when writing to the same file.
    // Must be refactored to allow multiple logger on console, and only one for a given file.

    SpdlogLogger::SpdlogLogger(const std::string &category)
    {
        std::clog << "spdlogger ctor";

        try {
            auto loggerConsole = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            loggerConsole->set_level(spdlog::level::debug);

            auto loggerFile = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt", true);
            loggerFile->set_level(spdlog::level::debug);

            spdlog::sinks_init_list loggers = {loggerConsole, loggerFile};

            m_logger = std::make_shared<spdlog::logger>(category, loggers.begin(), loggers.end());
            m_logger->set_level(spdlog::level::debug);
        } catch (const spdlog::spdlog_ex &exception) {
            std::cerr << exception.what() << std::endl;
        }
    }

    SpdlogLogger::~SpdlogLogger()
    {
        std::clog << "spdlogger dtor" << std::endl;
    }

    void SpdlogLogger::trace(const std::string &msg) const
    {
        m_logger->trace(msg);
    }

    void SpdlogLogger::debug(const std::string &msg) const
    {
        m_logger->debug(msg);
    }

    void SpdlogLogger::error(const std::string &msg) const
    {
        m_logger->error(msg);
    }

    void SpdlogLogger::warning(const std::string &msg) const
    {
        m_logger->warn(msg);
    }

    void SpdlogLogger::info(const std::string &msg) const
    {
        m_logger->info(msg);
    }
}// namespace ecge