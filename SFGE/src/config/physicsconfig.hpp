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

#include "iconfiguration.hpp"
#include "types.hpp"

namespace sfge::config
{
    class Physics : public IConfiguration
    {
    public:
        enum class Key : int32_t
        {
            PixelsPerMeter = 0
        };

    public:
        Physics();

        void setValue(const std::string &key, const std::string &value) override;
        void reset() override;

        [[nodiscard]] std::string getName() const override;
        const std::unordered_map<std::string, std::string> &getKeysValues() const override;

        [[nodiscard]] std::string getValue(Key key) const;
        void setValue(Key key, int value);
        void setValue(Key key, float value);
        void setValue(Key key, const std::string &value);

    public:
        template<typename T>
        typename std::enable_if_t<std::is_same_v<int, T>, T>
        getValue(Key key) const
        {
            return std::stoi(m_values.at(KeyToString(key).name));
        }

        template<typename T>
        typename std::enable_if_t<std::is_same_v<float, T>, T>
        getValue(Key key) const
        {
            return std::stof(m_values.at(KeyToString(key).name));
        }

    private:
        [[nodiscard]] static ConfigKey KeyToString(Key key);

    private:
        std::unordered_map<std::string, std::string> m_values;
    };
}// namespace sfge::config
