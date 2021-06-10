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

#include "typeparser.hpp"

#include <iostream>
#include <sstream>

namespace sfge::config
{
    void TypeParser::setValue(const std::string &value)
    {
        m_valueStr = value;
    }

    void TypeParser::setValue(const std::any &value)
    {
        m_valueAny = value;
    }

    void TypeParser::setType(Type type)
    {
        m_type = type;
    }

    std::string TypeParser::toString() const
    {
        std::string value;

        switch (m_type) {
            case Type::String:
                value = std::any_cast<std::string>(m_valueAny);
                break;
            case Type::Int:
                value = std::to_string(std::any_cast<int>(m_valueAny));
                break;
            case Type::Float:
                value = std::to_string(std::any_cast<float>(m_valueAny));
                break;
            case Type::Double:
                value = std::to_string(std::any_cast<double>(m_valueAny));
                break;
            case Type::Bool:
                std::ostringstream oss;
                oss << std::boolalpha << std::any_cast<bool>(m_valueAny);
                value = oss.str();
                break;
        }
        return value;
    }

    std::any TypeParser::toAny() const
    {
        std::any value;

        switch (m_type) {
            case Type::String:
                value = m_valueStr;
                break;
            case Type::Int:
                value = std::stoi(m_valueStr);
                break;
            case Type::Float:
                value = std::stof(m_valueStr);
                break;
            case Type::Double:
                value = std::stod(m_valueStr);
                break;
            case Type::Bool:
                bool boolean = false;
                std::istringstream(m_valueStr) >> std::boolalpha >> boolean;
                value = boolean;
                break;
        }
        return value;
    }
}// namespace sfge::config