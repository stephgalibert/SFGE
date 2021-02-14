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

#include <memory>

namespace sfge::config
{
    class Global;
    class Renderer;
    class Physics;
}// namespace sfge::config

namespace sfge::services
{
    struct IConfigurationManagerService {
        virtual ~IConfigurationManagerService() = default;

        virtual void load() = 0;
        virtual void save() = 0;

        [[nodiscard]] virtual std::shared_ptr<config::Global> getGlobal() const = 0;
        [[nodiscard]] virtual std::shared_ptr<config::Renderer> getRenderer() const = 0;
        [[nodiscard]] virtual std::shared_ptr<config::Physics> getPhysics() const = 0;
    };
}// namespace sfge::services