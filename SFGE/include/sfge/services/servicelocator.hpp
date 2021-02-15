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

#include <cassert>
#include <memory>
#include <unordered_map>

namespace sfge::services
{
    class ServiceLocator
    {
    private:
        static std::unordered_map<size_t, std::shared_ptr<void>> &getServices();

    public:
        template<typename T, typename U>
        static typename std::enable_if_t<std::is_base_of_v<T, U>>
        Provide();

        template<typename T>
        static std::shared_ptr<T> Get();
    };

}// namespace sfge::services

#include "servicelocator.inl"
