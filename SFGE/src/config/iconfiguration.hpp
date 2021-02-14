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

#include <string>
#include <unordered_map>
#include <vector>

namespace sfge::config
{
    struct IConfiguration {
        virtual ~IConfiguration() = default;

        virtual void setValue(const std::string &key, const std::string &value) = 0;
        virtual void reset() = 0;

        [[nodiscard]] virtual std::string getName() const = 0;
        [[nodiscard]] virtual const std::unordered_map<std::string, std::string> &getKeysValues() const = 0;
    };
}// namespace sfge::config