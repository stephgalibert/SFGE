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

namespace sfge::config
{
    std::string Global::GetLoggingFilePathKeyName()
    {
        return "LoggingFilePath";
    }

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
        const bool ret = setValue(GetLoggingFilePathKeyName(), value);
        if (!ret) {
            std::cout << "failed to set logging file path, value=" << value << std::endl;
        }
    }

    std::string Global::getLoggingFilePath() const
    {
        return getValueString(GetLoggingFilePathKeyName());
    }

    const std::set<KeyDefinition> &Global::getKeyDefinitions() const
    {
        static const std::set<KeyDefinition> keys = {
                {{GetLoggingFilePathKeyName(), Type::String, std::string("logs/log.txt")}}};
        return keys;
    }

}// namespace sfge::config
