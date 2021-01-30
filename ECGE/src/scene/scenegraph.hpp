#pragma once

#include <memory>
#include <vector>

namespace ecge
{
    class AGameObject;

    class SceneGraph
    {
    public:
        // Mocked scene graph
        // TODO: ECS Scene Graph
        std::vector<std::unique_ptr<AGameObject>> gameObjects;
    };
}// namespace ecge
