#include "rendersystem.hpp"

#include "sfge/components.hpp"

#include <iostream>

namespace sfge
{
    void RenderSystem::setRenderTarget(sf::RenderTarget *target)
    {
        m_renderTarget = target;
    }

    void RenderSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<ecs::Renderable>();
        for (auto entity : view) {
            auto &r = view.get<ecs::Renderable>(entity);
            m_renderTarget->draw(*r.shape);
        }
    }
}
