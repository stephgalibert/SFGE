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

#include <any>
#include <set>
#include <string>
#include <unordered_map>

#include "key.hpp"
#include "sfge/exceptions/badtype.hpp"

namespace sfge::config
{
    class AConfiguration
    {
    public:
        virtual ~AConfiguration() = default;

        [[nodiscard]] virtual std::string getName() const = 0;

        void reset();

        bool setValue(const std::string &key, const std::string &value);
        bool setValue(const std::string &key, int value);
        bool setValue(const std::string &key, float value);
        bool setValue(const std::string &key, double value);
        bool setValue(const std::string &key, bool value);

        std::string getValueString(const std::string &key) const;
        int getValueInt(const std::string &key) const;
        float getValueFloat(const std::string &key) const;
        double getValueDouble(const std::string &key) const;
        bool getValueBool(const std::string &key) const;

        [[nodiscard]] const std::unordered_map<std::string, std::string> &getKeysValues() const;

    protected:
        virtual const std::set<KeyInfo> &getKeys() const = 0;

    private:
        template<Type KeyType>
        static void ensureType(Type type)
        {
            if (KeyType != type) {
                const std::string msg(toString(type) + " is not a " + toString(KeyType));
                throw exception::BadType(msg.c_str());
            }
        }

    private:
        std::unordered_map<std::string, std::string> m_values;
        // std::unordered_map<std::string, std::any> m_values;
    };
}// namespace sfge::config