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

#include "component.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

namespace sfge::ecs
{
    class Renderable : public Component
    {
    public:
        Renderable() = default;
        explicit Renderable(sf::Shape *shape);
        Renderable(const Renderable &rhs) = delete;
        Renderable(Renderable &&rhs) noexcept;
        ~Renderable() = default;

        Renderable &operator=(const Renderable &rhs) = delete;
        Renderable &operator=(Renderable &&rhs) noexcept;

        [[nodiscard]] const std::unique_ptr<sf::Shape> &shape() const;

        void setOrigin(float x, float y);
        void setPosition(float x, float y);
        void setScale(float x, float y);
        void setRotation_RADIANS(float angle);
        void setRotation_DEGREES(float angle);
        void setTexture(sf::Texture *texture);
        void setColor(const sf::Color &color);

    private:
        std::unique_ptr<sf::Shape> m_shape;
    };
}// namespace sfge::ecs