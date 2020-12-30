#pragma once

#include <vector>
#include <memory>

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
}
