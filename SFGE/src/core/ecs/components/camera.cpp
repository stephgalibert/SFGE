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
        m_view.setViewport(rect);
        if (m_renderTarget)
            m_renderTarget->setView(m_view);
    }

    void Camera::setSize(float x, float y)
    {
        m_view.setSize(x, y);
        if (m_renderTarget)
            m_renderTarget->setView(m_view);
    }

    void Camera::setCenter(float x, float y)
    {
        m_view.setCenter(x, y);
        if (m_renderTarget)
            m_renderTarget->setView(m_view);
    }

    void Camera::setRotation_DEGREES(float angle)
    {
        m_view.setRotation(angle);
        if (m_renderTarget)
            m_renderTarget->setView(m_view);
    }

    const sf::FloatRect &Camera::getViewport() const
    {
        return m_view.getViewport();
    }

    const sf::Vector2f &Camera::getSize() const
    {
        return m_view.getSize();
    }

    const sf::Vector2f &Camera::getCenter() const
    {
        return m_view.getCenter();
    }

    float Camera::getRotation_DEGREES() const
    {
        return m_view.getRotation();
    }

    void Camera::setActive(bool value)
    {
        m_active = value;
    }

    bool Camera::isActive() const
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
