//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#include "spdloglogger.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <iostream>

namespace sfge
{
    auto &SpdlogLogger::GetFilesLogger()
    {
        static std::unordered_map<std::string, std::shared_ptr<spdlog::sinks::basic_file_sink_mt>> filesLogger;
        return filesLogger;
    }

    auto SpdlogLogger::CreateFileSink(const std::string &filename)
    {
        std::shared_ptr<spdlog::sinks::basic_file_sink_mt> sink;

        try {
            sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename, true);
            sink->set_level(spdlog::level::debug);
        } catch (spdlog::spdlog_ex &exception) {
            std::cerr << exception.what() << std::endl;
        }
        return sink;
    }

    bool SpdlogLogger::create(const std::string &category)
    {
        try {
            auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            consoleSink->set_level(spdlog::level::debug);

            m_logger = std::make_shared<spdlog::logger>(category, consoleSink);
            m_logger->set_level(spdlog::level::debug);
            m_category = category;
        } catch (const spdlog::spdlog_ex &exception) {
            std::cerr << exception.what() << std::endl;
            return false;
        }
        return true;
    }

    bool SpdlogLogger::addLoggingFile(const std::string &filename)
    {
        if (!m_logger)
            return false;

        auto &filesLogger = GetFilesLogger();
        auto found = filesLogger.find(filename);

        if (found == filesLogger.end()) {
            auto sink = CreateFileSink(filename);
            const auto [iterator, success] = filesLogger.insert({filename, sink});
            found = iterator;
        }

        if (found == filesLogger.end()) {
            return false;
        }
        m_logger->sinks().push_back(found->second);
        return true;
    }

    std::string SpdlogLogger::getCategory() const
    {
        return m_category;
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
}// namespace sfge