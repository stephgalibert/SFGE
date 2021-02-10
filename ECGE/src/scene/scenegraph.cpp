#include "scenegraph.hpp"

#include "ecge/agameobject.hpp"
#include "ecge/logger/logger.h"

namespace ecge
{
    SceneGraph::SceneGraph()
    {
        m_logger = Logger::CreateLogger("SceneGraph");
        m_logger->addLoggingFile("logs/log.txt");
    }

    SceneGraph::~SceneGraph()
    {
        for (auto &obj : m_gameObjects) {
            m_logger->debug("Destroying GameObject #" + std::to_string(obj->getId()));
            obj->onDestroyed();
        }
        Logger::RemoveLogger(m_logger);
    }

    void SceneGraph::insert(const std::shared_ptr<AGameObject> &obj)
    {
        m_logger->debug("Spawning GameObject #" + std::to_string(obj->getId()));
        m_gameObjects.push_back(obj);
    }

}// namespace ecge