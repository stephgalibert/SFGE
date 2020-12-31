#include "rendersystem.hpp"

#include "ecge/components.hpp"

namespace ecge
{
    RenderSystem::RenderSystem()
    {
        m_view.setSize(1280, 720);
        m_view.setCenter(0, 0);
    }

    void RenderSystem::setRenderTarget(sf::RenderTarget *target)
    {
        m_renderTarget = target;
        m_renderTarget->setView(m_view);
    }

    void RenderSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<const ecs::Renderable, const ecs::Transformable>();
        for (const auto entity : view) {
            const auto &r = view.get<const ecs::Renderable>(entity);
            // Maybe having an observer instead of setting this every frame is better..
            const auto &t = view.get<const ecs::Transformable>(entity);
            // Transformable is stocking meters coordinate
            // Using 50 pixels per meter
            // Position referring to its center
            r.shape->setScale(t.scale.x * 50, t.scale.y * 50);
            r.shape->setPosition(t.position.x * 50 - r.shape->getScale().x / 2,
                                 t.position.y * 50 - r.shape->getScale().y / 2);
            r.shape->setRotation(t.angle * 180 / b2_pi);
            m_renderTarget->draw(*r.shape);
        }
    }
}
