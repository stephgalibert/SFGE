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

#include "scenemanager.hpp"

#include "sfge/scene/ascene.hpp"

#include <iostream>

namespace sfge
{
    void SceneManager::onWindowClosing()
    {
        m_currentScene->destroy();
    }

    void SceneManager::onKeyboardEvent(const input::KeyboardEvent &event)
    {
        m_currentScene->onKeyboardEvent(event);
    }

    void SceneManager::onMouseButtonEvent(const input::MouseButtonEvent &event)
    {
        m_currentScene->onMouseButtonEvent(event);
    }

    void SceneManager::update(float dt)
    {
        m_currentScene->update(dt);
    }

    void SceneManager::draw()
    {
        m_currentScene->draw();
    }

    void SceneManager::setScene(std::unique_ptr<AScene> scene)
    {
        // TODO: push into a build queue and only then, set m_currentScene
        m_currentScene = std::move(scene);
        m_currentScene->init();
    }

    const std::unique_ptr<AScene> &SceneManager::scene() const
    {
        return m_currentScene;
    }
}// namespace sfge