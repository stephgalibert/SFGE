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

#include "keydefinition.hpp"
#include "sfge/exceptions/badtype.hpp"

namespace sfge::config
{
    class AConfiguration
    {
    public:
        virtual ~AConfiguration() = default;

        [[nodiscard]] virtual std::string getName() const = 0;
        [[nodiscard]] virtual const std::set<KeyDefinition> &getKeyDefinitions() const = 0;

        bool initValue(const std::string &key, const std::string &value);
        [[nodiscard]] std::unordered_map<std::string, std::string> retrieveNormalizedValues() const;

    protected:
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

    private:
        const Type *getKeyType(const std::string &key) const;

    private:
        std::unordered_map<std::string, std::any> m_values;
    };
}// namespace sfge::config