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

#include "typeparser.hpp"
#include "typevalidator.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

namespace sfge::config
{
    bool AConfiguration::initValue(const std::string &key, const std::string &value)
    {
        const std::set<KeyDefinition> &keys = getKeyDefinitions();
        const auto keyDefinitionFound = findKeyDefinition(keys, key);
        if (keyDefinitionFound == keys.end()) {
            return false;
        }

        const TypeValidator typeValidator;
        if (!typeValidator(keyDefinitionFound->type, value)) {
            std::ostringstream oss;
            oss << key << ": " << value << " is not a " << toString(keyDefinitionFound->type);
            throw exception::BadType(oss.str());
        }

        TypeParser typeParser;
        typeParser.setType(keyDefinitionFound->type);
        typeParser.setValue(value);
        m_values[key] = typeParser.toAny();
        return true;
    }

    void AConfiguration::reset()
    {
        const std::set<KeyDefinition> &keyDefinitions = getKeyDefinitions();

        m_values.clear();
        for (const KeyDefinition &keyDefinition : keyDefinitions) {
            m_values[keyDefinition.name] = keyDefinition.defaultValue;
        }
    }

    bool AConfiguration::setValue(const std::string &key, const std::string &value)
    {
        const Type *type = getKeyType(key);
        if (!type || *type != Type::String) {
            return false;
        }
        m_values[key] = value;
        return true;
    }

    bool AConfiguration::setValue(const std::string &key, int value)
    {
        const Type *type = getKeyType(key);
        if (!type || *type != Type::Int) {
            return false;
        }
        m_values[key] = value;
        return true;
    }

    bool AConfiguration::setValue(const std::string &key, float value)
    {
        const Type *type = getKeyType(key);
        if (!type || *type != Type::Float) {
            return false;
        }
        m_values[key] = value;
        return true;
    }

    bool AConfiguration::setValue(const std::string &key, double value)
    {
        const Type *type = getKeyType(key);
        if (!type || *type != Type::Double) {
            return false;
        }
        m_values[key] = value;
        return true;
    }

    bool AConfiguration::setValue(const std::string &key, bool value)
    {
        const Type *type = getKeyType(key);
        if (!type || *type != Type::Bool) {
            return false;
        }
        m_values[key] = value;
        return true;
    }

    std::unordered_map<std::string, std::string> AConfiguration::retrieveNormalizedValues() const
    {
        std::unordered_map<std::string, std::string> normalizedValues;

        TypeParser typeParser;
        for (const auto &it : m_values) {
            const Type *type = getKeyType(it.first);
            assert(type);
            typeParser.setValue(it.second);
            typeParser.setType(*type);
            normalizedValues[it.first] = typeParser.toString();
        }
        return normalizedValues;
    }

    std::string AConfiguration::getValueString(const std::string &key) const
    {
        if (!getKeyType(key)) {
            return "";
        }
        return std::any_cast<std::string>(m_values.at(key));
    }

    int AConfiguration::getValueInt(const std::string &key) const
    {
        if (!getKeyType(key)) {
            return -1;
        }
        return std::any_cast<int>(m_values.at(key));
    }

    float AConfiguration::getValueFloat(const std::string &key) const
    {
        if (!getKeyType(key)) {
            return -1;
        }
        return std::any_cast<float>(m_values.at(key));
    }

    double AConfiguration::getValueDouble(const std::string &key) const
    {
        if (!getKeyType(key)) {
            return -1;
        }
        return std::any_cast<double>(m_values.at(key));
    }

    bool AConfiguration::getValueBool(const std::string &key) const
    {
        if (!getKeyType(key)) {
            return false;
        }
        return std::any_cast<bool>(m_values.at(key));
    }

    const Type *AConfiguration::getKeyType(const std::string &key) const
    {
        const std::set<KeyDefinition> &keys = getKeyDefinitions();
        const auto keyDefinitionFound = findKeyDefinition(keys, key);
        if (keyDefinitionFound == keys.end()) {
            return nullptr;
        }
        return &keyDefinitionFound->type;
    }
}// namespace sfge::config