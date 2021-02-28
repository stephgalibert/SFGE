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
    void Renderable::setShape(sf::Shape *shape)
    {
        m_shape.reset(shape);
        getRegistry()->patch<Renderable>(getEntity());
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

    const std::unique_ptr<sf::Shape> &Renderable::shape() const
    {
        return m_shape;
    }

    const sf::Vector2f &Renderable::getOrigin() const
    {
        return m_shape->getOrigin();
    }

    const sf::Vector2f &Renderable::getPosition() const
    {
        return m_shape->getPosition();
    }

    const sf::Vector2f &Renderable::getScale() const
    {
        return m_shape->getScale();
    }

    const sf::Color &Renderable::getColor() const
    {
        return m_shape->getFillColor();
    }

    float Renderable::getAngle_DEGREES() const
    {
        return m_shape->getRotation();
    }

    float Renderable::getAngle_RADIANS() const
    {
        return m_shape->getRotation() * b2_pi / 180.f;
    }
}// namespace sfge::ecs