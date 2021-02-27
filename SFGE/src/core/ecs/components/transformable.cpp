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
#include "sfge/gameobject/agameobject.hpp"

#include <box2d/b2_common.h>

namespace sfge::ecs
{
    void Transformable::setPosition(const sf::Vector2f &pos)
    {
        m_position = pos;
        getRegistry()->patch<Transformable>(getEntity());
    }

    void Transformable::setScale(const sf::Vector2f &scale)
    {
        m_scale = scale;
        getRegistry()->patch<Transformable>(getEntity());
    }

    void Transformable::setAngle_RADIANS(float angle)
    {
        m_angle = angle * 180 / b2_pi;
        getRegistry()->patch<Transformable>(getEntity());
    }

    void Transformable::setAngle_DEGREES(float angle)
    {
        m_angle = angle;
        getRegistry()->patch<Transformable>(getEntity());
    }

    void Transformable::setTransform(const sf::Vector2f &pos, float radians)
    {
        m_position = pos;
        m_angle = radians * 180 / b2_pi;
        getRegistry()->patch<Transformable>(getEntity());
    }

    sf::Vector2f Transformable::getPosition() const
    {
        return m_position;
    }

    sf::Vector2f Transformable::getScale() const
    {
        return m_scale;
    }

    float Transformable::getAngle_RADIANS() const
    {
        return m_angle * b2_pi / 180;
    }

    float Transformable::getAngle_DEGREES() const
    {
        return m_angle;
    }
}// namespace sfge::ecs