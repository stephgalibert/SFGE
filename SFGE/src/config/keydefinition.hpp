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
#include <string>

#include "types.hpp"

namespace sfge::config
{
    struct KeyDefinition {
        std::string name;
        Type type = Type::Int;
        std::any defaultValue;
    };

    inline bool operator<(const KeyDefinition &lhs, const KeyDefinition &rhs)
    {
        return lhs.name < rhs.name;
    }

    inline std::set<KeyDefinition>::const_iterator findKeyDefinition(const std::set<KeyDefinition> &keys, const std::string &name)
    {
        return keys.find({name});
    }
}// namespace sfge::config