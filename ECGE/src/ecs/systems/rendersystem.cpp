#include "rendersystem.hpp"

#include "ecge/components.hpp"

namespace ecge
{
    void RenderSystem::setRenderTarget(sf::RenderTarget *target)
    {
        m_renderTarget = target;
    }

    void RenderSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<const ecs::Renderable, const ecs::Transformable>();
        for (const auto entity : view) {
            const auto &r = view.get<const ecs::Renderable>(entity);
            // Maybe having an observer instead of setting this every frame is better..
            const auto &t = view.get<const ecs::Transformable>(entity);
            r.shape->setPosition(t.position);
            r.shape->setScale(t.scale);
            r.shape->setRotation(t.angle);
            m_renderTarget->draw(*r.shape);
        }
    }
}
