#include "scenegraph.hpp"

#include "sfge/gameobject/agameobject.hpp"
#include "sfge/logger/logger.h"

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