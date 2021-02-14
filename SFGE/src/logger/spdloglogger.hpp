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

#pragma once

#include "sfge/logger/ilogger.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "iostream"
#include <memory>

namespace sfge
{
    class SpdlogLogger : public ILogger
    {
    private:
        static auto &GetFilesLogger();
        static auto CreateFileSink(const std::string &filename);

    public:
        ~SpdlogLogger()
        {
            std::clog << "delete spdlogger" << std::endl;
        }

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