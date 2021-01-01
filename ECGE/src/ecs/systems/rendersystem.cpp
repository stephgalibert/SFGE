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
        // Using 50 pixels per meter TODO: make an user config
        const float meterPerPixel = 50.f;
        const float pixelsPerMeter = 0.02f;

        auto view = registry.view<const ecs::Renderable, const ecs::Transformable>();
        for (const auto entity : view) {
            const auto &r = view.get<const ecs::Renderable>(entity);
            // Maybe having an observer instead of setting this every frame is better..
            const auto &t = view.get<const ecs::Transformable>(entity);
            r.shape->setOrigin(t.scale.x * meterPerPixel / 2.f, t.scale.y * meterPerPixel / 2.f);
            r.shape->setPosition(t.position.x * meterPerPixel, t.position.y * meterPerPixel);
            r.shape->setRotation(t.angle * 180 / b2_pi);
            m_renderTarget->draw(*r.shape);
        }
    }
}
