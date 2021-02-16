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

#include "sfge/components/renderable.hpp"

#include <box2d/b2_common.h>

namespace sfge::ecs
{
    Renderable::Renderable(sf::Shape *shape)
        : m_shape(shape)
    {
    }

    Renderable::Renderable(Renderable &&rhs) noexcept
        : Component(std::move(rhs))
    {
        m_shape = std::move(rhs.m_shape);
    }

    Renderable &Renderable::operator=(Renderable &&rhs) noexcept
    {
        m_shape = std::move(rhs.m_shape);
        Component::operator=(std::move(rhs));
        return *this;
    }

    const std::unique_ptr<sf::Shape> &Renderable::shape() const
    {
        return m_shape;
    }

    void Renderable::setOrigin(float x, float y)
    {
        m_shape->setOrigin({x, y});
    }

    void Renderable::setPosition(float x, float y)
    {
        m_shape->setPosition({x, y});
    }

    void Renderable::setScale(float x, float y)
    {
        m_shape->setScale({x, y});
    }

    void Renderable::setRotation_RADIANS(float angle)
    {
        m_shape->setRotation(angle * 180 / b2_pi);
    }

    void Renderable::setRotation_DEGREES(float angle)
    {
        m_shape->setRotation(angle);
    }

    void Renderable::setTexture(sf::Texture *texture)
    {
        assert(texture);
        m_shape->setTexture(texture);
    }

    void Renderable::setColor(const sf::Color &color)
    {
        m_shape->setFillColor(color);
    }
}// namespace sfge::ecs