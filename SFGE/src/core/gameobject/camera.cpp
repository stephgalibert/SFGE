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

#include "sfge/gameobject/camera.hpp"
#include "sfge/components/camera.hpp"

namespace sfge::gameobjects
{
    void Camera::onCreated()
    {
        addComponent<sfge::ecs::Camera>();
    }

    void Camera::onDestroyed()
    {
    }

    void Camera::setRenderTarget(sf::RenderTarget *target)
    {
        auto &camera = component<sfge::ecs::Camera>();
        camera.setRenderTarget(target);
    }

    void Camera::setViewport(const sf::FloatRect &rect)
    {
        auto &camera = component<sfge::ecs::Camera>();
        camera.setViewport(rect);
    }

    void Camera::setSize(float x, float y)
    {
        auto &camera = component<sfge::ecs::Camera>();
        camera.setSize(x, y);
    }

    void Camera::setCenter(float x, float y)
    {
        auto &camera = component<sfge::ecs::Camera>();
        camera.setCenter(x, y);
    }

    void Camera::setRotation(float degree)
    {
        auto &camera = component<sfge::ecs::Camera>();
        camera.setRotation(degree);
    }

    void Camera::setActive(bool value)
    {
        auto &camera = component<sfge::ecs::Camera>();
        camera.setActive(value);
    }
}// namespace sfge::gameobjects