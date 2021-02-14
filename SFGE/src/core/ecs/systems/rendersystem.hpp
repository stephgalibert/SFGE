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

#include "isystem.hpp"

#include <SFML/Graphics.hpp>

namespace sfge::ecs
{
    class RenderSystem : public ISystem
    {
    public:
        RenderSystem();
        void setRenderTarget(sf::RenderTarget *target);
        void update(entt::registry &registry, float dt) override;

    private:
        sf::RenderTarget *m_renderTarget = nullptr;
        sf::View m_view;
    };
}// namespace sfge::ecs
