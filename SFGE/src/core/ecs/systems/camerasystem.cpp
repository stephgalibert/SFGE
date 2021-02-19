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

#include "camerasystem.hpp"

#include "sfge/components/camera.hpp"
#include "sfge/components/renderable.hpp"

namespace sfge::ecs
{
    void CameraSystem::update(entt::registry &registry, float dt)
    {
        auto cameraView = registry.view<const ecs::Camera>();
        auto renderableView = registry.view<const ecs::Renderable>();

        for (const auto cameraEntity : cameraView) {
            const auto &camera = cameraView.get<const ecs::Camera>(cameraEntity);
            if (camera.isActive()) {
                for (const auto renderableEntity : renderableView) {
                    const auto &renderable = renderableView.get<const ecs::Renderable>(renderableEntity);
                    camera.getRenderTarget()->draw(*renderable.shape());
                }
            }
        }
    }
}// namespace sfge::ecs
