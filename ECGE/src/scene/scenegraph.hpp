#pragma once

#include <memory>
#include <vector>

namespace ecge
{
    class ILogger;
    class AGameObject;

    class SceneGraph
    {
    public:
        SceneGraph();
        ~SceneGraph();

        void insert(const std::shared_ptr<AGameObject> &obj);
        void clear();

    private:
        std::shared_ptr<ILogger> m_logger;
        std::vector<std::shared_ptr<AGameObject>> m_gameObjects;
    };
}// namespace ecge
