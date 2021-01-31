#pragma once

#include "ilogger.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <memory>

namespace ecge
{
    class SpdlogLogger : public ILogger
    {
    private:
        static auto &GetFilesLogger();
        static auto CreateFileSink(const std::string &filename);

    public:
        explicit SpdlogLogger(const std::string &category);

        bool addLoggingFile(const std::string &filename) override;

        void trace(const std::string &msg) const override;
        void debug(const std::string &msg) const override;
        void info(const std::string &msg) const override;
        void warning(const std::string &msg) const override;
        void error(const std::string &msg) const override;

    private:
        std::shared_ptr<spdlog::logger> m_logger;
    };
}// namespace ecge