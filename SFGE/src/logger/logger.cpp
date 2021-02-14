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

#include "sfge/logger/logger.hpp"
#include "sfge/logger/ilogger.hpp"

#include "spdloglogger.hpp"

namespace sfge
{
    auto &Logger::getLoggers()
    {
        static std::unordered_map<std::string, std::shared_ptr<ILogger>> loggers;
        return loggers;
    }

    std::shared_ptr<ILogger> Logger::CreateLogger(const std::string &category)
    {
        std::unordered_map<std::string, std::shared_ptr<ILogger>> &loggers = getLoggers();
        const auto found = loggers.find(category);
        if (found != loggers.end()) {
            return found->second;
        }

        auto logger = std::make_shared<SpdlogLogger>();
        if (!logger->create(category))
            return nullptr;

        const auto [iterator, success] = loggers.insert({category, logger});
        return iterator->second;
    }

    bool Logger::RemoveLogger(const std::string &category)
    {
        std::unordered_map<std::string, std::shared_ptr<ILogger>> &loggers = getLoggers();
        return static_cast<bool>(loggers.erase(category));
    }

    bool Logger::RemoveLogger(const std::shared_ptr<ILogger> &logger)
    {
        const std::string category = logger->getCategory();
        return RemoveLogger(category);
    }

    bool Logger::AddLoggingFile(const std::string &category, const std::string &filename)
    {
        std::shared_ptr<ILogger> logger = GetLogger(category);
        if (!logger)
            return false;
        return logger->addLoggingFile(filename);
    }

    std::shared_ptr<ILogger> Logger::GetLogger(const std::string &category)
    {
        std::unordered_map<std::string, std::shared_ptr<ILogger>> &loggers = getLoggers();
        auto it = loggers.find(category);

        if (it != loggers.end())
            return it->second;
        return nullptr;
    }
}// namespace sfge
