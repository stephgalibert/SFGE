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

#include "ilogger.hpp"

#include "sfge/services/iloggerservice.hpp"

#include <unordered_map>

namespace sfge
{
    class Logger : public services::ILoggerService
    {
    public:
        std::shared_ptr<ILogger> getOrCreateLogger(const std::string &category) override;
        bool removeLogger(const std::string &category) override;
        bool removeLogger(const std::shared_ptr<ILogger> &logger) override;

        bool addLoggingFile(const std::string &category, const std::string &filename) override;

        std::shared_ptr<ILogger> getLogger(const std::string &category) override;

    private:
        std::unordered_map<std::string, std::shared_ptr<ILogger>> m_loggers;
    };
}// namespace sfge
