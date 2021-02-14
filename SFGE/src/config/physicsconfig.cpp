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
    std::string Physics::KeyToString(Key key)
    {
        static const std::unordered_map<Key, std::string> map = {
                {{Key::PixelsPerMeter}, {"PixelsPerMeter"}}};
        return map.at(key);
    }

    const auto &Physics::GetDefault()
    {
        static const std::unordered_map<std::string, std::string> values = {
                {{KeyToString(Key::PixelsPerMeter)}, {"50"}}};
        return values;
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
        m_values[key] = value;
    }

    void Physics::reset()
    {
        m_values = GetDefault();
    }

    std::string Physics::getValue(Key key) const
    {
        return m_values.at(KeyToString(key));
    }

    void Physics::setValue(Key key, int value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Physics::setValue(Key key, float value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Physics::setValue(Key key, const std::string &value)
    {
        setValue(KeyToString(key), value);
    }
}// namespace sfge::config
