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

#include "sfge/components/camera.hpp"

namespace sfge::ecs
{
    void Camera::setRenderTarget(sf::RenderTarget *target)
    {
        m_renderTarget = target;
    }
    void Camera::setViewport(const sf::FloatRect &rect)
    {
        assert(m_renderTarget);
        m_view.setViewport(rect);
        m_renderTarget->setView(m_view);
    }

    void Camera::setSize(float x, float y)
    {
        assert(m_renderTarget);
        m_view.setSize(x, y);
        m_renderTarget->setView(m_view);
    }

    void Camera::setCenter(float x, float y)
    {
        assert(m_renderTarget);
        m_view.setCenter(x, y);
        m_renderTarget->setView(m_view);
    }

    void Camera::setRotation(float degree)
    {
        assert(m_renderTarget);
        m_view.setRotation(degree);
        m_renderTarget->setView(m_view);
    }

    void Camera::setActive(bool value)
    {
        m_active = value;
    }

    [[nodiscard]] bool Camera::isActive() const
    {
        return m_active;
    }

    const sf::View &Camera::getView() const
    {
        return m_view;
    }

    sf::RenderTarget *Camera::getRenderTarget() const
    {
        return m_renderTarget;
    }
}// namespace sfge::ecs
