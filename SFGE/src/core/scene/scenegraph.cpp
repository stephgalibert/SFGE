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

#include "scenegraph.hpp"

#include "sfge/gameobject/agameobject.hpp"
#include "sfge/logger/logger.hpp"

namespace sfge
{
    SceneGraph::SceneGraph()
    {
        m_logger = Logger::CreateLogger("SceneGraph");
        m_logger->addLoggingFile("logs/log.txt");
    }

    SceneGraph::~SceneGraph()
    {
        clear();
        Logger::RemoveLogger(m_logger);
    }

    void SceneGraph::insert(const std::shared_ptr<AGameObject> &obj)
    {
        m_logger->debug("Spawning GameObject #" + std::to_string(obj->getId()));
        m_gameObjects.push_back(obj);
    }

    void SceneGraph::clear()
    {
        for (auto &obj : m_gameObjects) {
            m_logger->debug("Destroying GameObject #" + std::to_string(obj->getId()));
            obj->onDestroyed();
        }
    }

}// namespace sfge