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

#include "core/application/eventlistener.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

namespace sfge
{
    class AScene;

    class SceneManager : public input::EventHandler
    {
    public:
        void onWindowClosing() override;
        void onKeyboardEvent(const input::KeyboardEvent &event) override;
        void onMouseButtonEvent(const input::MouseButtonEvent &event) override;
        void onMouseMoveEvent(const input::MouseMoveEvent &event) override;
        void onWindowResized(const input::WindowResizedEvent &event) override;
        void onFocusChanged(const input::FocusChangedEvent &event) override;

        void update(float dt);
        void draw();

        void addScene(std::unique_ptr<AScene> scene);
        [[nodiscard]] unsigned int getSceneCount() const;

    private:
        std::vector<std::unique_ptr<AScene>> m_scenes;
    };
}// namespace sfge