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

#include "globalconfig.hpp"
#include <iostream>

#define LOGGING_FILE_PATH_KEY_NAME "LoggingFilePath"

namespace sfge::config
{
    Global::Global()
    {
        reset();
    }

    std::string Global::getName() const
    {
        return "Global";
    }

    void Global::setLoggingFilePath(const std::string &value)
    {
        const bool ret = setValue(LOGGING_FILE_PATH_KEY_NAME, value);
        if (!ret) {
            std::cout << "failed to set logging file path, value=" << value << std::endl;
        }
    }

    std::string Global::getLoggingFilePath() const
    {
        return getValueString(LOGGING_FILE_PATH_KEY_NAME);
    }

    const std::set<KeyInfo> &Global::getKeys() const
    {
        static const std::set<KeyInfo> keys = {
                {{LOGGING_FILE_PATH_KEY_NAME, Type::String, "logs/log.txt"}}};
        return keys;
    }

}// namespace sfge::config
