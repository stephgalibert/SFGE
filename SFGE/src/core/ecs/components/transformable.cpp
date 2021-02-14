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

#include "sfge/components/transformable.hpp"

#include <iostream>

namespace sfge::ecs
{
    void Transformable::setPosition(const sf::Vector2f &pos)
    {
        m_registry->patch<Transformable>(m_entity, [&pos](Transformable &transform) {
            transform.m_position = pos;
        });
    }

    void Transformable::setScale(const sf::Vector2f &scale)
    {
        m_registry->patch<Transformable>(m_entity, [&scale](Transformable &transform) {
            transform.m_scale = scale;
        });
    }

    void Transformable::setAngle(float radians)
    {
        m_registry->patch<Transformable>(m_entity, [radians](Transformable &transform) {
            transform.m_radians = radians;
        });
    }

    void Transformable::setTransform(const sf::Vector2f &pos, float radians)
    {
        m_registry->patch<Transformable>(m_entity, [&pos, radians](Transformable &transform) {
            transform.m_position = pos;
            transform.m_radians = radians;
        });
    }

    sf::Vector2f Transformable::getPosition() const
    {
        return m_position;
    }

    sf::Vector2f Transformable::getScale() const
    {
        return m_scale;
    }

    float Transformable::getAngleRadians() const
    {
        return m_radians;
    }
}// namespace sfge::ecs