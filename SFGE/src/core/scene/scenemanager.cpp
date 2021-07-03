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
    //    void SceneManager::onWindowClosing()
    //    {
    //        for (auto &scene : m_scenes)
    //            scene->onWindowClosing();
    //    }

    void SceneManager::onEvent(const sf::Event &event)
    {
        for (auto &scene : m_scenes)
            scene->onEvent(event);
    }

    void SceneManager::update(float dt)
    {
        for (auto &scene : m_scenes)
            scene->update(dt);
    }

    void SceneManager::draw()
    {
        for (auto &scene : m_scenes)
            scene->draw();
    }

    void SceneManager::addScene(std::unique_ptr<AScene> scene)
    {
        // TODO: push into a build queue and only then, set m_currentScene
        scene->init();
        m_scenes.push_back(std::move(scene));
    }

    unsigned int SceneManager::getSceneCount() const
    {
        return m_scenes.size();
    }
}// namespace sfge