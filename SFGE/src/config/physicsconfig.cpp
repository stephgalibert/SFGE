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

#include "physicsconfig.hpp"

namespace sfge::config
{
    ConfigKey Physics::KeyToString(Key key)
    {
        static const std::unordered_map<Key, ConfigKey> map = {
                {{Key::PixelsPerMeter}, {"PixelsPerMeter", Type::Float}}};
        return map.at(key);
    }

    Physics::Physics()
    {
        reset();
    }

    std::string Physics::getName() const
    {
        return "Physics";
    }

    const std::unordered_map<std::string, std::string> &Physics::getKeysValues() const
    {
        return m_values;
    }

    void Physics::setValue(const std::string &key, const std::string &value)
    {
        // TODO: Check type matching key here. If error, throw an exception.
        //   - Using Design pattern Decorator?
        //   - Define which exception to be thrown.


        m_values[key] = value;
    }

    void Physics::reset()
    {
        static const std::unordered_map<std::string, std::string> values = {
                {{KeyToString(Key::PixelsPerMeter).name}, {"50.0"}}};
        m_values = values;
    }

    std::string Physics::getValue(Key key) const
    {
        return m_values.at(KeyToString(key).name);
    }

    void Physics::setValue(Key key, int value)
    {
        setValue(KeyToString(key).name, std::to_string(value));
    }

    void Physics::setValue(Key key, float value)
    {
        setValue(KeyToString(key).name, std::to_string(value));
    }

    void Physics::setValue(Key key, const std::string &value)
    {
        setValue(KeyToString(key).name, value);
    }
}// namespace sfge::config
