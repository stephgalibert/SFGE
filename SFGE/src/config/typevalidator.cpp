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

#include "typevalidator.hpp"
#include <iostream>
#include <sstream>

namespace sfge::config
{
    const std::unordered_map<Type, std::function<bool(const std::string &)>> TypeValidator::Validators = {
            {Type::Int, [](const std::string &value) { return TypeValidator::validateInt(value); }},
            {Type::Float, [](const std::string &value) { return TypeValidator::validateFloat(value); }},
            {Type::Double, [](const std::string &value) { return TypeValidator::validateDouble(value); }},
            {Type::Bool, [](const std::string &value) { return TypeValidator::validateBool(value); }},
            {Type::String, [](const std::string &value) { return TypeValidator::validateString(value); }}};

    bool TypeValidator::operator()(Type type, const std::string &value) const
    {
        const auto found = Validators.find(type);
        if (found != Validators.end()) {
            return found->second(value);
        }
        return false;
    }

    bool TypeValidator::validateInt(const std::string &value)
    {
        return std::all_of(value.begin(), value.end(), ::isdigit);
    }

    bool TypeValidator::validateFloat(const std::string &value)
    {
        std::istringstream iss(value);

        float f;
        iss >> f;
        bool success = !iss.fail();
        std::cout << "value " << value << " is float=" << success << std::endl;

        return success;
    }

    bool TypeValidator::validateDouble(const std::string &value)
    {
        std::istringstream iss(value);

        double d;
        iss >> d;
        bool success = !iss.fail();
        std::cout << "value " << value << " is double=" << success << std::endl;
        return success;
    }

    bool TypeValidator::validateBool(const std::string &value)
    {
        std::istringstream iss(value);

        bool b;
        iss >> std::boolalpha >> b;
        bool success = !iss.fail();
        std::cout << "value " << value << " is bool=" << success << std::endl;
        return success;
    }

    bool TypeValidator::validateString(const std::string &value)
    {
        return std::all_of(value.begin(), value.end(), ::isgraph);
    }
}// namespace sfge::config