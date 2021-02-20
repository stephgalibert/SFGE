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

#include "sfge/components/base/component.hpp"

#include <SFML/Graphics.hpp>

namespace sfge::ecs
{
    class Transformable : public Component
    {
    public:
        void setPosition(const sf::Vector2f &pos);
        void setScale(const sf::Vector2f &scale);
        void setAngle(float radians);
        void setTransform(const sf::Vector2f &pos, float angleRadians);

        [[nodiscard]] sf::Vector2f getPosition() const;
        [[nodiscard]] sf::Vector2f getScale() const;
        [[nodiscard]] float getAngleRadians() const;

    private:
        sf::Vector2f m_position;      // meters
        sf::Vector2f m_scale = {1, 1};// meters
        float m_radians = 0.f;        // radians
    };
}// namespace sfge::ecs