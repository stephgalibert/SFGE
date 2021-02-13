#pragma once

#include "sfge/logger/ilogger.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <memory>

namespace sfge
{
    class SpdlogLogger : public ILogger
    {
    private:
        static auto &GetFilesLogger();
        static auto CreateFileSink(const std::string &filename);

    public:
        bool create(const std::string &category) override;
        bool addLoggingFile(const std::string &filename) override;
        [[nodiscard]] std::string getCategory() const override;

        void trace(const std::string &msg) const override;
        void debug(const std::string &msg) const override;
        void info(const std::string &msg) const override;
        void warning(const std::string &msg) const override;
        void error(const std::string &msg) const override;

    private:
        std::string m_category;
        std::shared_ptr<spdlog::logger> m_logger;
    };
}// namespace sfge