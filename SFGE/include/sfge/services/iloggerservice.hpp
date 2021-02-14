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

#include <memory>
#include <string>

namespace sfge
{
    struct ILogger;
}

namespace sfge::services
{
    struct ILoggerService {
        virtual ~ILoggerService() = default;

        virtual std::shared_ptr<ILogger> createLogger(const std::string &category) = 0;
        virtual bool removeLogger(const std::string &category) = 0;
        virtual bool removeLogger(const std::shared_ptr<ILogger> &logger) = 0;

        virtual bool addLoggingFile(const std::string &category, const std::string &filename) = 0;
        virtual std::shared_ptr<ILogger> getLogger(const std::string &category) = 0;
    };
}// namespace sfge::services