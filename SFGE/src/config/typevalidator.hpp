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

#include "types.hpp"

#include <functional>
#include <string>
#include <unordered_map>

namespace sfge::config
{
    class TypeValidator
    {
    public:
        bool operator()(Type type, const std::string &value);

    private:
        static bool validateInt(const std::string &value);
        static bool validateFloat(const std::string &value);
        static bool validateDouble(const std::string &value);
        static bool validateBool(const std::string &value);
        static bool validateString(const std::string &value);

    private:
        static const std::unordered_map<Type, std::function<bool(const std::string &)>> Validators;
    };
}// namespace sfge::config
