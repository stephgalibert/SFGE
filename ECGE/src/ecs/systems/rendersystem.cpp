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
            // Using 50 pixels per meter
            r.shape->setOrigin(t.scale.x * 50.f / 2.f, t.scale.y * 50.f / 2.f);
            r.shape->setPosition(t.position.x * 50, t.position.y * 50);
            r.shape->setRotation(t.angle * 180 / b2_pi);
            m_renderTarget->draw(*r.shape);
        }
    }
}
