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

namespace sfge::config
{
    std::string Global::KeyToString(Key key)
    {
        static const std::unordered_map<Key, std::string> map = {
                {{Key::LoggingFile}, {"LoggingFile"}}};
        return map.at(key);
    }

    Global::Global()
    {
        reset();
    }

    void Global::setValue(const std::string &key, const std::string &value)
    {
    }

    void Global::reset()
    {
        static const std::unordered_map<std::string, std::string> values = {
                {{KeyToString(Key::LoggingFile)}, {"logs/log.txt"}}};
        m_values = values;
    }

    std::string Global::getName() const
    {
        return "Global";
    }

    const std::unordered_map<std::string, std::string> &Global::getKeysValues() const
    {
        return m_values;
    }

    std::string Global::getValue(Key key) const
    {
        return m_values.at(KeyToString(key));
    }

    void Global::setValue(Key key, int value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Global::setValue(Key key, float value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Global::setValue(Key key, const std::string &value)
    {
        setValue(KeyToString(key), value);
    }

}// namespace sfge::config
