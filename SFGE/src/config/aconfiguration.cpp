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

#include "aconfiguration.hpp"

#include "typevalidator.hpp"
#include <sstream>

namespace sfge::config
{
    void AConfiguration::reset()
    {
        const std::set<KeyInfo> &keys = getKeys();

        m_values.clear();
        for (const KeyInfo &key : keys) {
            m_values[key.name] = key.defaultValue;
        }
    }

    bool AConfiguration::setValue(const std::string &key, const std::string &value)
    {
        const std::set<KeyInfo> &keys = getKeys();
        const auto keyFound = findKey(keys, key);

        if (keyFound == keys.end()) {
            return false;
        }

        const TypeValidator typeValidator;
        if (!typeValidator(keyFound->type, value)) {
            std::ostringstream oss;
            oss << key << ": " << value << " is not a " << toString(keyFound->type);
            throw exception::BadType(oss.str());
        }

        m_values[key] = value;
        return true;
    }

    bool AConfiguration::setValue(const std::string &key, int value)
    {
        return setValue(key, std::to_string(value));
    }

    bool AConfiguration::setValue(const std::string &key, float value)
    {
        return setValue(key, std::to_string(value));
    }

    bool AConfiguration::setValue(const std::string &key, double value)
    {
        return setValue(key, std::to_string(value));
    }

    bool AConfiguration::setValue(const std::string &key, bool value)
    {
        return setValue(key, std::to_string(value));
    }

    const std::unordered_map<std::string, std::string> &AConfiguration::getKeysValues() const
    {
        return m_values;
    }

    std::string AConfiguration::getValueString(const std::string &key) const
    {
        const std::set<KeyInfo> &keys = getKeys();
        const auto keyFound = findKey(keys, key);

        if (keyFound == keys.end()) {
            return "";
        }
        ensureType<Type::String>(keyFound->type);
        return m_values.at(keyFound->name);
    }

    int AConfiguration::getValueInt(const std::string &key) const
    {
        const std::set<KeyInfo> &keys = getKeys();
        const auto keyFound = findKey(keys, key);

        if (keyFound == keys.end()) {
            return -1;
        }
        ensureType<Type::Int>(keyFound->type);
        return std::stoi(m_values.at(keyFound->name));
    }

    float AConfiguration::getValueFloat(const std::string &key) const
    {
        const std::set<KeyInfo> &keys = getKeys();
        const auto keyFound = findKey(keys, key);

        if (keyFound == keys.end()) {
            return -1;
        }
        ensureType<Type::Float>(keyFound->type);
        return std::stof(m_values.at(keyFound->name));
    }

    double AConfiguration::getValueDouble(const std::string &key) const
    {
        const std::set<KeyInfo> &keys = getKeys();
        const auto keyFound = findKey(keys, key);

        if (keyFound == keys.end()) {
            return -1;
        }
        ensureType<Type::Double>(keyFound->type);
        return std::stod(m_values.at(keyFound->name));
    }

    bool AConfiguration::getValueBool(const std::string &key) const
    {
        const std::set<KeyInfo> &keys = getKeys();
        const auto keyFound = findKey(keys, key);

        if (keyFound == keys.end()) {
            return -1;
        }
        ensureType<Type::Bool>(keyFound->type);
        bool b = false;
        std::istringstream(m_values.at(keyFound->name)) >> std::boolalpha >> b;
        return b;
    }

}// namespace sfge::config