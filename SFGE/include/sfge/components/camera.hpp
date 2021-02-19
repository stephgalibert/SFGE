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

#include "sfge/components/interfaces/component.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/View.hpp>

namespace sfge::ecs
{
    class Camera : public Component
    {
    public:
        void setRenderTarget(sf::RenderTarget *target);
        void setViewport(const sf::FloatRect &rect);
        void setSize(float x, float y);
        void setCenter(float x, float y);
        void setRotation(float degree);
        void setActive(bool value);

        [[nodiscard]] bool isActive() const;
        [[nodiscard]] const sf::View &getView() const;
        [[nodiscard]] sf::RenderTarget *getRenderTarget() const;

    private:
        sf::RenderTarget *m_renderTarget = nullptr;
        sf::View m_view;
        bool m_active;
    };
}// namespace sfge::ecs
