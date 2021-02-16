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

#include "rendersystem.hpp"

#include "sfge/components/renderable.hpp"
#include "sfge/components/transformable.hpp"

namespace sfge::ecs
{
    RenderSystem::RenderSystem()
    {
        m_view.setSize(1280, 720);
        m_view.setCenter(0, 0);
    }

    void RenderSystem::setRenderTarget(sf::RenderTarget *target)
    {
        m_renderTarget = target;
        m_renderTarget->setView(m_view);
    }

    void RenderSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<const ecs::Renderable>();
        for (const auto entity : view) {
            const auto &renderable = view.get<const ecs::Renderable>(entity);
            auto pos = renderable.shape()->getPosition();
            m_renderTarget->draw(*renderable.shape());
        }
    }
}// namespace sfge::ecs
