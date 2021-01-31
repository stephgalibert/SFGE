#pragma once

#include "ilogger.h"

#include <spdlog/spdlog.h>

#include <memory>

namespace ecge
{
    class SpdlogLogger : public ILogger
    {
    public:
        SpdlogLogger(const std::string &category);
        ~SpdlogLogger();

        void trace(const std::string &msg) const override;
        void debug(const std::string &msg) const override;
        void info(const std::string &msg) const override;
        void warning(const std::string &msg) const override;
        void error(const std::string &msg) const override;

    private:
        std::shared_ptr<spdlog::logger> m_logger;
    };
}// namespace ecge